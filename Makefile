SRCS		=	srcs/so_long.c srcs/parsing/get_next_line.c srcs/parsing/get_next_line_utils.c \
				srcs/parsing/fill_map.c srcs/parsing/utils.c srcs/parsing/check_wall.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		= 	-Wall -Wextra -Werror -I./srcs/includes

NAME		= 	so_long

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re bonus