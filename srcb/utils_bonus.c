#include "../so_long_bonus.h"

int	go_malloc(void **str, int taille)
{
	(*str) = malloc(taille);
	if (str)
		return (0);
	return (1);
}

char	*ft_strdup(char *s1)
{
	char	*dest;
	int		i;
	int		len;

	dest = 0;
	i = 0;
	len = ft_strlen(s1) + 1;
	dest = (char *)malloc(sizeof(char) * len);
	if (dest == 0)
		return (0);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_itoa(int n)
{
	char	buff[12];
	int		i;
	int		sign;
	int		tmp;

	buff[11] = 0;
	i = 10;
	sign = 0;
	if (n < 0)
		sign = 1;
	if (!n)
		buff[i--] = '0';
	while (n)
	{
		tmp = n % 10;
		if (tmp < 0)
			tmp = -tmp;
		buff[i--] = tmp + '0';
		n /= 10;
	}
	if (sign)
		buff[i--] = '-';
	return (ft_strdup(buff + i + 1));
}

void	ft_init(t_data *data, int i)
{
	data->nblines = 0;
	data->sizeline = 0;
	data->posx = 0;
	data->posy = 0;
	data->i = 0;
	data->c = 0;
	data->a = 0;
	data->m = 0;
	data->f = 0;
	data->life = 5;
	data->move = 0;
	data->exit = 0;
	data->error = 0;
	data->map = NULL;
	data->line = NULL;
	data->mlx.img = NULL;
	data->mlx.win = NULL;
	data->mlx.mlx = NULL;
	data->map = NULL;
	data->list = NULL;
	data->str = NULL;
	while (++i < 10)
		data->text[i].img = NULL;
}
