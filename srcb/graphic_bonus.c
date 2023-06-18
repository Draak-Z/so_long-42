#include "../so_long_bonus.h"

void	movement(t_data *data, int x, int y)
{
	int		i;

	i = 5;
	data->move++;
	if (data->map[data->posx][data->posy] == 'E' && !data->c)
		data->exit = 1;
	if (data->map[data->posx][data->posy] == 'C')
	{
		while (++i < 10)
			add_frames(data, i, x, y);
		data->map[data->posx][data->posy] = '0';
		data->c--;
	}
	if (data->map[data->posx][data->posy] == 'M')
	{
		data->map[data->posx][data->posy] = '0';
		data->life--;
	}
	if (data->life == 0)
		end(data, 1);
}

int	key_press(int keycode, t_data *data)
{
	int	oldx;
	int	oldy;

	oldx = data->posx;
	oldy = data->posy;
	if (keycode == K_W)
		if (data->map[data->posx - 1][data->posy] != '1')
			data->posx--;
	if (keycode == K_S)
		if (data->map[data->posx + 1][data->posy] != '1')
			data->posx++;
	if (keycode == K_A)
		if (data->map[data->posx][data->posy - 1] != '1')
			data->posy--;
	if (keycode == K_D)
		if (data->map[data->posx][data->posy + 1] != '1')
			data->posy++;
	if (keycode == K_ESC)
		ft_close(data, 0);
	if (data->posx != oldx || data->posy != oldy)
		movement(data, oldx, oldy);
	return (0);
}

void	graphic(t_data *data)
{
	data->i = 0;
	data->exit = 0;
	data->rx = data->sizeline * TSIZE;
	data->ry = data->nblines * TSIZE;
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		ft_error(data, "Mlx init failed\n");
	ft_get_text_img(data);
	data->mlx.img = mlx_new_image(data->mlx.mlx, data->rx, data->ry);
	data->mlx.addr = (int *)mlx_get_data_addr(data->mlx.img,
			&data->mlx.bits_per_pixel, &data->mlx.line_length,
			&data->mlx.endian);
	data->mlx.win = mlx_new_window(data->mlx.mlx, data->rx,
			data->ry, "./so_long");
	mlx_hook(data->mlx.win, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx.win, 33, 1L << 17, ft_close, data);
	mlx_loop_hook(data->mlx.mlx, &draw, data);
	mlx_loop(data->mlx.mlx);
}
