/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loda-sil <loda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:59:54 by loda-sil          #+#    #+#             */
/*   Updated: 2025/11/11 14:04:55 by loda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "../lib/minilibx-linux/mlx.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include <fcntl.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_img {
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_img;

typedef struct s_map {
	char **layout;
	t_img wall;
	t_img floor;
	t_img collect;
	t_img exit;
	t_img open_exit;
	int width;
	int height;
} t_map;

typedef struct s_player
{
	t_img sprite[4];
	int direction;
	int steps;
	int x;
	int y;
} t_player;

typedef struct s_game
{
	t_mlx mlx;
	t_img data;
	t_map map;
	t_player player;
} t_game;

# define SPRITE_SIZE 32

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECT 'C'
# define EXIT 'E'

# define PLAYER_UP 0
# define PLAYER_LEFT 1
# define PLAYER_RIGHT 2
# define PLAYER_DOWN 3

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# define ESC 65307

// Error functions
int	message_error(char *message);
int	exit_error(char *message);

// Map functions
int map_read(t_game *game, char *map_path);
int map_check(t_game *game);
int map_check_extension(char *filename, char *extension);
int map_is_valid_char(char c);
int map_count_element(char **layout, char element);
int map_validate_element_counts(int player, int collect, int exit);

#endif
