#include "../so_long_bonus.h"

void	ft_walls(t_data *data, int i)
{
	i = -1;
	while (data->map[0][++i])
		if (data->map[0][i] != '1')
			data->error = 6;
	i = -1;
	while (data->map[++i])
		if (data->map[i][data->sizeline - 1] != '1')
			data->error = 6;
	i = -1;
	while (data->map[data->nblines - 1][++i])
		if (data->map[data->nblines - 1][i] != '1')
			data->error = 6;
}

int	ft_get_map(char *str, t_data *data, int j)
{
	while (str[++j])
	{
		if (str[j] == 'P')
		{
			if (data->posx || data->posy)
				data->error = 4;
			data->posx = data->i;
			data->posy = j;
			data->map[data->i][j] = '0';
		}
		else
			data->map[data->i][j] = str[j];
		if (str[j] == 'E')
		{
			if (data->exit)
				data->error = 5;
			data->exit = 1;
		}
	}
	data->map[data->i][j] = '\0';
	data->i++;
	return (0);
}

void	ft_parse_map(char *str, t_data *data)
{
	int	i;

	i = -1;
	if (str[0] != '1')
		data->error = 1;
	else
	{
		while (str[++i])
		{
			if (str[i] != '1' && str[i] != '0' && str[i]
				!= 'C' && str[i] != 'E' && str[i] != 'P' && str[i] != 'M')
				data->error = 2;
			if (str[i] == 'C')
				data->c++;
		}
		if (i != data->sizeline && data->sizeline != 0)
			data->error = 3;
		data->sizeline = i;
		data->nblines++;
	}
}
