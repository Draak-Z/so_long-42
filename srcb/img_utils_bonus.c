#include "../so_long_bonus.h"

void	display_counters(t_data *data)
{
	data->str = ft_itoa(data->move);
	mlx_string_put(data->mlx.mlx, data->mlx.win, 26, 34, 0x000000, data->str);
	free(data->str);
	data->str = ft_itoa(data->life);
	mlx_string_put(data->mlx.mlx, data->mlx.win, 94, 34, 0xFF0000, data->str);
	free(data->str);
	data->str = ft_itoa(data->c);
	mlx_string_put(data->mlx.mlx, data->mlx.win, 158, 34, 0x0000FF, data->str);
	free(data->str);
}

void	swap_monsters(t_data *data, int x, int y, int var)
{
	if (data->map[x][y + var] == '0')
	{
		data->map[x][y + var] = 'M';
		data->map[x][y] = '0';
		if (data->posx == x && data->posy == y + var)
		{
			data->map[x][y + var] = '0';
			data->life--;
			if (data->life == 0)
				end(data, 1);
		}
	}
}

void	monsters(t_data *data, int x, int y)
{
	if (data->f == 0)
	{
		if (data->m == 0)
			data->m = 1;
		else
			data->m = 0;
		while (data->map[++x])
		{
			y = -1;
			while (data->map[x][++y])
			{
				if (data->map[x][y] == 'M')
				{
					if (!data->m)
						swap_monsters(data, x, y, -1);
					if (data->m)
						swap_monsters(data, x, y++, 1);
				}
			}
		}
	}
	data->f++;
	if (data->f == 42)
		data->f = 0;
}
