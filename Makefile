NAME = so_long

SRCS = src/main.c

GNL_SRCS = lib/get_next_line/get_next_line.c \
			lib/get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o) $(GNL_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes -Ilib/mlx -Ilib/get_next_line -Ilib/libft

MLX = -Llib/mlx -lmlx -L/usr/lib -lXext -lX11 -lm -lz
LIBFT = lib/libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib/mlx
	make -C lib/libft
	$(CC) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C lib/mlx
	make clean -C lib/libft

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/mlx
	make fclean -C lib/libft

re: fclean all

.PHONY: all clean fclean re
