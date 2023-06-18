#include "../so_long.h"

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
	return (4);
}

int	draw(t_data *data)
{
	int	y;
	int	x;

	x = -1;
	while (data->map[++x])
	{
		y = -1;
		while (data->map[x][++y])
		{
			draw_cube(data, data->text[4], x * TSIZE, y * TSIZE);
			if (data->map[x][y] == '1' || data->map[x][y] == 'E' ||
				data->map[x][y] == 'C')
				draw_cube(data, data->text[texnum(data, x, y)],
					x * TSIZE, y * TSIZE);
			if (data->posx == x && data->posy == y)
				draw_cube(data, data->text[2], x * TSIZE, y * TSIZE);
		}
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	if (data->exit && !data->c)
		ft_close(data, 0);
	return (0);
}
