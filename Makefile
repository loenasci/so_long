NAME = so_long

HEADERS = includes/so_long.h

SRCS = src/main.c \
		src/game/game_init.c \
		src/map/map_read.c \
		src/map/map_check.c \
		src/map/map_path.c \
		src/map/map_utils.c \
		src/game/game_render.c \
		src/game/game_movement.c \
		src/game/game_exit.c \
		src/utils/ft_error.c \
		src/utils/ft_free.c

GNL_SRCS = lib/get_next_line/get_next_line.c \
			lib/get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o) $(GNL_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -Iincludes -Ilib/minilibx-linux -Ilib/get_next_line -Ilib/libft -Ilib/ft_printf

MLX = -Llib/minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz
LIBFT = lib/libft/libft.a
LIBFTPRINTF = lib/ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib/minilibx-linux
	make -C lib/libft
	make -C lib/ft_printf
	$(CC) $(OBJS) $(LIBFT) $(LIBFTPRINTF) $(MLX) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C lib/minilibx-linux
	make clean -C lib/libft
	make clean -C lib/ft_printf


fclean: clean
	rm -f $(NAME)
	make clean -C lib/minilibx-linux
	make fclean -C lib/libft
	make fclean -C lib/ft_printf

re: fclean all

.PHONY: all clean fclean re
