SRCS		=	srcs/so_long.c srcs/parsing/get_next_line.c srcs/parsing/get_next_line_utils.c \
				srcs/parsing/fill_map.c srcs/parsing/utils.c srcs/parsing/check_wall.c srcs/parsing/parse_name.c \
				srcs/parsing/check_char_map.c srcs/parsing/check_collectible.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		= 	-Wall -Wextra -Werror -I./srcs/includes

NAME		= 	so_long
	
MLX			= 	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)	

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re bonus