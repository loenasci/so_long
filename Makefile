NAME = so_long

SRCS = src/main.c

GNL_SRCS = lib/get_next_line/get_next_line.c \
			lib/get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o) $(GNL_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes -Ilib/minilibx-linux -Ilib/get_next_line -Ilib/libft

MLX = -Llib/minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz
LIBFT = lib/libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib/minilibx-linux
	make -C lib/libft
	$(CC) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C lib/minilibx-linux
	make clean -C lib/libft

fclean: clean
	rm -f $(NAME)
	make clean -C lib/minilibx-linux
	make fclean -C lib/libft

re: fclean all

.PHONY: all clean fclean re
