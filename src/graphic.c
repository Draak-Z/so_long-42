#include "../so_long.h"

void	ft_get_text_addr(t_data *data)
{
	data->text[0].addr = (int *)mlx_get_data_addr(data->text[0].img,
			&data->text[0].bits_per_pixel, &data->text[0].line_length,
			&data->text[0].endian);
	data->text[1].addr = (int *)mlx_get_data_addr(data->text[1].img,
			&data->text[1].bits_per_pixel, &data->text[1].line_length,
			&data->text[1].endian);
	data->text[2].addr = (int *)mlx_get_data_addr(data->text[2].img,
			&data->text[2].bits_per_pixel, &data->text[2].line_length,
			&data->text[2].endian);
	data->text[3].addr = (int *)mlx_get_data_addr(data->text[3].img,
			&data->text[3].bits_per_pixel, &data->text[3].line_length,
			&data->text[3].endian);
	data->text[4].addr = (int *)mlx_get_data_addr(data->text[4].img,
			&data->text[4].bits_per_pixel, &data->text[4].line_length,
			&data->text[4].endian);
}

void	ft_get_text_img(t_data *data)
{
	data->text[0].img = mlx_xpm_file_to_image(data->mlx.mlx,
			"./t/w.xpm", &(data->text[0].w), &(data->text[0].h));
	if (!data->text[0].img)
		ft_error(data, "Invalid wall texture\n");
	data->text[1].img = mlx_xpm_file_to_image(data->mlx.mlx,
			"./t/d.xpm", &(data->text[1].w), &(data->text[1].h));
	if (!data->text[1].img)
		ft_error(data, "Invalid exit texture\n");
	data->text[2].img = mlx_xpm_file_to_image(data->mlx.mlx,
			"./t/p.xpm", &(data->text[2].w), &(data->text[2].h));
	if (!data->text[2].img)
		ft_error(data, "Invalid player texture\n");
	data->text[3].img = mlx_xpm_file_to_image(data->mlx.mlx,
			"./t/c.xpm", &(data->text[3].w), &(data->text[3].h));
	if (!data->text[3].img)
		ft_error(data, "Invalid collectible texture\n");
	data->text[4].img = mlx_xpm_file_to_image(data->mlx.mlx,
			"./t/f.xpm", &(data->text[4].w), &(data->text[4].h));
	if (!data->text[4].img)
		ft_error(data, "Invalid floor texture\n");
	ft_get_text_addr(data);
}

void	movement(t_data *data, char *str)
{
	data->move++;
	str = ft_itoa(data->move);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
	if (data->map[data->posx][data->posy] == 'E' && !data->c)
		data->exit = 1;
	if (data->map[data->posx][data->posy] == 'C')
	{
		data->map[data->posx][data->posy] = '0';
		data->c--;
	}
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
		movement(data, NULL);
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
