SRCS		=	srcs/so_long.c									\
				srcs/parsing/get_next_line.c					\
				srcs/parsing/get_next_line_utils.c				\
				srcs/parsing/utils.c							\
				srcs/parsing/parse_name_and_fill_map.c			\
				srcs/parsing/check_char_map.c					\
				srcs/parsing/check_wall_and_collectible.c		\
				srcs/game/start_game.c							\
				srcs/game/ft_move.c								\
				srcs/game/utils.c								\

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		= 	-Wall -Wextra -Werror -g3 -I./srcs/includes

NAME		= 	so_long
	
MLX			= 	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
	@make -C ./mlx_linux
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)	

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re bonus

