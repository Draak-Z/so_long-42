#include "../so_long.h"

void	ft_check_errors(t_data *data)
{
	if (data->error == 4)
		ft_error(data, "More than 1 player\n");
	if (data->error == 5)
		ft_error(data, "More than 1 exit\n");
	ft_walls(data, -1);
	if (data->error == 6)
		ft_error(data, "Hole in the map\n");
	if (!data->posx || !data->posy)
		ft_error(data, "No player\n");
	if (!data->exit)
		ft_error(data, "No exit\n");
	if (!data->c)
		ft_error(data, "No collectible\n");
}

void	ft_error(t_data *data, char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	if (data->error == 1)
		write(2, "Invalid line in the file\n", 25);
	if (data->error == 2)
		write(2, "Invalid character in the map\n", 29);
	if (data->error == 3)
		write(2, "The map is not a rectangle\n", 27);
	ft_close(data, 1);
}

void	free_data(t_data *data, int i)
{
	if (data->map)
	{
		while (++i < data->nblines)
			free(data->map[i]);
		free(data->map);
	}
	if (data->list)
		ft_lstclear(&data->list);
}

int	ft_close(t_data *data, int ex)
{
	int	i;

	i = -1;
	free_data(data, -1);
	if (data->mlx.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.img);
	while (++i < 5)
		if (data->text[i].img)
			mlx_destroy_image(data->mlx.mlx, data->text[i].img);
	if (data->mlx.win)
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	if (data->mlx.mlx)
		mlx_destroy_display(data->mlx.mlx);
	if (data->mlx.mlx)
		free(data->mlx.mlx);
	if (ex != 1 && ex != 0)
		ex = 0;
	exit(ex);
	return (0);
}
