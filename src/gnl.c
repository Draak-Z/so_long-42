#include "../so_long.h"

char	*ft_strndup(char *s1, int n)
{
	char	*dest;
	int		i;
	int		len;

	dest = 0;
	i = 0;
	len = ft_strlen(s1) + 1;
	if (go_malloc((void *)&dest, (sizeof(char) * len)))
		return (NULL);
	while (i < n && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char s2)
{
	char	*dst;
	int		i;

	i = -1;
	if (s1 == NULL)
		return (ft_strndup(&s2, 1));
	if (go_malloc((void *)&dst, (sizeof(char) * (ft_strlen(s1) + 2))))
	{
		free(s1);
		return (NULL);
	}
	while (s1[++i])
		dst[i] = s1[i];
	dst[i] = s2;
	dst[i + 1] = '\0';
	free(s1);
	return (dst);
}

int	gnl(int fd, char **line)
{
	char	c;
	int		ret;

	if (fd < 0 || fd > 255 || !line)
		return (-1);
	*line = 0;
	ret = 1;
	c = 0;
	while (c != '\n' && ret == 1)
	{
		*line = ft_strjoin(*line, c);
		if (*line == NULL)
			return (-1);
		ret = read(fd, &c, 1);
		if (ret < 0)
			return (-1);
	}
	if (ret == 0)
		return (0);
	return (1);
}
