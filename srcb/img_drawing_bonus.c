#include "../so_long_bonus.h"

void	draw_cube(t_data *data, t_mlx text, int ry, int rx)
{
	int	x;
	int	y;

	x = -1;
	while (++x < TSIZE)
	{
		y = -1;
		while (++y < TSIZE)
			if (text.addr[text.h * y + x] != 0)
				data->mlx.addr[(ry + y) *data->rx + (rx + x)]
					= text.addr[text.h * y + x];
	}
}

int	texnum(t_data *data, int x, int y)
{
	if (data->map[x][y] == '1')
		return (0);
	if (data->map[x][y] == 'E')
		return (1);
	if (data->map[x][y] == 'C')
		return (3);
	if (data->map[x][y] == 'M')
		return (5);
	return (4);
}

void	draw_bis(t_data *data, int x, int y, int i)
{
	while (data->map[++x])
	{
		y = -1;
		while (data->map[x][++y])
			if (data->map[x][y] == 'C' && (data->posx == x && data->posy == y))
				draw_cube(data, data->text[i], x * TSIZE, y * TSIZE);
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
}

int	draw(t_data *data)
{
	int	y;
	int	x;

	monsters(data, -1, -1);
	x = -1;
	while (data->map[++x])
	{
		y = -1;
		while (data->map[x][++y])
		{
			draw_cube(data, data->text[4], x * TSIZE, y * TSIZE);
			if (data->map[x][y] == '1' || data->map[x][y] == 'E' ||
				data->map[x][y] == 'C' || data->map[x][y] == 'M')
				draw_cube(data, data->text[texnum(data, x, y)],
					x * TSIZE, y * TSIZE);
			if (data->posx == x && data->posy == y && !data->a)
				draw_cube(data, data->text[2], x * TSIZE, y * TSIZE);
		}
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	display_counters(data);
	if (data->exit && !data->c)
		end(data, 0);
	return (0);
}

void	add_frames(t_data *data, int i, int x, int y)
{
	int	k;

	k = -1;
	data->a = 1;
	draw(data);
	while (++k < 100)
		draw_bis(data, -1, -1, i);
	draw_cube(data, data->text[2], x * TSIZE, y * TSIZE);
	data->a = 0;
}
