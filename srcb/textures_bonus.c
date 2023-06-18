#include "../so_long_bonus.h"

void	ft_get_more_addr(t_data *data)
{
	data->text[6].addr = (int *)mlx_get_data_addr(data->text[6].img,
			&data->text[6].bits_per_pixel, &data->text[6].line_length,
			&data->text[6].endian);
	data->text[7].addr = (int *)mlx_get_data_addr(data->text[7].img,
			&data->text[7].bits_per_pixel, &data->text[7].line_length,
			&data->text[7].endian);
	data->text[8].addr = (int *)mlx_get_data_addr(data->text[8].img,
			&data->text[8].bits_per_pixel, &data->text[8].line_length,
			&data->text[8].endian);
	data->text[9].addr = (int *)mlx_get_data_addr(data->text[9].img,
			&data->text[9].bits_per_pixel, &data->text[9].line_length,
			&data->text[9].endian);
}

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
	data->text[5].addr = (int *)mlx_get_data_addr(data->text[5].img,
			&data->text[5].bits_per_pixel, &data->text[5].line_length,
			&data->text[5].endian);
	ft_get_more_addr(data);
}

void	ft_get_more_img(t_data *data)
{
	data->text[6].img = mlx_xpm_file_to_image(data->mlx.mlx,
			"./t/c1.xpm", &(data->text[6].w), &(data->text[6].h));
	if (!data->text[6].img)
		ft_error(data, "Invalid collectible texture\n");
	data->text[7].img = mlx_xpm_file_to_image(data->mlx.mlx,
			"./t/c2.xpm", &(data->text[7].w), &(data->text[7].h));
	if (!data->text[7].img)
		ft_error(data, "Invalid collectible texture\n");
	data->text[8].img = mlx_xpm_file_to_image(data->mlx.mlx,
			"./t/c3.xpm", &(data->text[8].w), &(data->text[8].h));
	if (!data->text[8].img)
		ft_error(data, "Invalid collectible texture\n");
	data->text[9].img = mlx_xpm_file_to_image(data->mlx.mlx,
			"./t/c4.xpm", &(data->text[9].w), &(data->text[9].h));
	if (!data->text[9].img)
		ft_error(data, "Invalid collectible texture\n");
	ft_get_text_addr(data);
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
	data->text[5].img = mlx_xpm_file_to_image(data->mlx.mlx,
			"./t/m.xpm", &(data->text[5].w), &(data->text[5].h));
	if (!data->text[5].img)
		ft_error(data, "Invalid monster texture\n");
	ft_get_more_img(data);
}
