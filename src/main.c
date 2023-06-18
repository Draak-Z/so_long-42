#include "../so_long.h"

void	ft_parsing_map(t_data *data, t_list *tmp, int i)
{
	if (go_malloc((void *)&data->map, (sizeof(char *) * (data->nblines + 1))))
		ft_error(data, "Malloc map failed\n");
	while (++i < data->nblines)
		if (go_malloc((void *)&data->map[i],
				(sizeof(char) * (data->sizeline + 1))))
			ft_error(data, "Malloc map failed\n");
	while (tmp)
	{
		ft_get_map(tmp->content, data, -1);
		tmp = tmp->next;
	}
	data->map[data->i] = NULL;
	ft_check_errors(data);
}

void	ft_parsing(char *fichier, t_data *data)
{
	int			fd;
	int			ret;

	ret = 1;
	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		ft_error(data, "Invalid .ber file\n");
	while (ret > 0)
	{
		ret = gnl(fd, &data->line);
		if (ret > -1 && data->error != 10)
			ft_lstadd_back(&data->list, ft_lstnew(data->line), data);
		if (ret == -1)
		{
			free(data->line);
			ft_error(data, "Unreadable file or directory\n");
		}
		ft_parse_map(data->line, data);
		if (data->error > 0)
			ft_error(data, "");
	}
	close(fd);
	if (data->sizeline == 0 || data->nblines == 0)
		ft_error(data, "Empty file\n");
	ft_parsing_map(data, data->list, -1);
}

void	ft_ber(char *str, t_data *data)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != '.')
	{
		if (!i)
			ft_error(data, "Map file extension is not .ber\n");
		i--;
	}
	if (str[i + 1] == 'b' && str[i + 2] == 'e' && str[i + 3] == 'r'
		&& str[i + 4] == '\0')
		ft_parsing(str, data);
	else
		ft_error(data, "Map file extension is not .ber\n");
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_init(&data, -1);
	if (argc == 2)
	{
		ft_ber(argv[1], &data);
		graphic(&data);
	}
	else
		write(2, "Error\nInvalid arguments\n", 24);
}
