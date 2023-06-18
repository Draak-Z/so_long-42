NAME = so_long

SRCS =	src/graphic.c\
		src/errors.c\
		src/ft_lst.c\
		src/gnl.c\
		src/utils.c\
		src/map_parser.c\
		src/img_drawing.c\
		src/main.c\

SRCSB = srcb/graphic_bonus.c\
		srcb/errors_bonus.c\
		src/ft_lst.c\
		src/gnl.c\
		srcb/utils_bonus.c\
		srcb/map_parser_bonus.c\
		srcb/img_drawing_bonus.c\
		srcb/img_utils_bonus.c\
		srcb/textures_bonus.c\
		srcb/main_bonus.c\

OBJS = ${SRCS:.c=.o}

OBJSB = ${SRCSB:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -c

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	${OBJS} compil_other
		${CC} -o ${NAME} ${OBJS} minilibx-linux/libmlx_Linux.a -lXext -lX11

bonus:	${OBJSB} compil_other
		${CC} -o ${NAME} ${OBJSB} minilibx-linux/libmlx_Linux.a -lXext -lX11	

clean:	clean_other
		${RM} ${OBJS} ${OBJSB}

fclean:		clean
			${RM} ${NAME}

compil_other:
		cd minilibx-linux && make

clean_other:
		cd minilibx-linux && make clean

re:		fclean all

.PHONY: clean all fclean re
