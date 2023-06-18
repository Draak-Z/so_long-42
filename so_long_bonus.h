#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "minilibx-linux/mlx.h"
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define K_A 97
# define K_D 100
# define K_Q 113
# define K_S 115
# define K_W 119
# define K_Z 122
# define K_ESC 65307
# define TSIZE 64

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				w;
	int				h;
}					t_mlx;

typedef struct s_data
{
	int				nblines;
	int				sizeline;
	char			**map;
	int				rx;
	int				ry;
	int				posx;
	int				posy;
	int				error;
	int				i;
	int				move;
	int				c;
	int				a;
	int				m;
	int				f;
	int				life;
	int				exit;
	char			*line;
	char			*str;
	t_mlx			mlx;
	t_mlx			text[10];
	t_list			*list;
}					t_data;

int					ft_lstsize(t_list *lst);
void				ft_lstclear(t_list **lst);
void				ft_lstadd_back(t_list **alst, t_list *new, t_data *data);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
int					ft_close(t_data *vars, int ex);
int					draw(t_data *data);
void				add_frames(t_data *data, int i, int x, int y);
int					go_malloc(void **str, int taille);
char				*ft_itoa(int n);
int					key_press(int keycode, t_data *data);
void				graphic(t_data *data);
void				ft_ber(char *str, t_data *data);
void				ft_parsing(char *fichier, t_data *data);
void				ft_parsing_map(t_data *data, t_list	*tmp, int i);
void				ft_init(t_data *data, int i);
void				ft_walls(t_data *data, int i);
void				ft_parse_map(char *str, t_data *data);
int					ft_get_map(char *str, t_data *data, int j);
void				ft_error(t_data *data, char *str);
void				ft_check_errors(t_data *data);
void				ft_get_text_addr(t_data *data);
void				ft_get_text_img(t_data *data);
size_t				ft_strlen(char *s);
int					gnl(int fd, char **line);
void				display_counters(t_data *data);
void				monsters(t_data *data, int x, int y);
void				end(t_data *data, int msg);

#endif
