/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loena <loena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:59:54 by loda-sil          #+#    #+#             */
/*   Updated: 2025/11/13 23:36:32 by loena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "../lib/minilibx-linux/mlx.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include <fcntl.h>

# define SPRITE_SIZE 32

# define WALL_SPRITE "assets/sprites/map/wall.xpm"
# define FLOOR_SPRITE "assets/sprites/map/floor.xpm"
# define COLLECT_SPRITE "assets/sprites/map/collect.xpm"
# define EXIT_SPRITE "assets/sprites/map/exit.xpm"
# define OPEN_EXIT_SPRITE "assets/sprites/map/open_exit.xpm"

# define PLAYER_UP_SPRITE "assets/sprites/player/up.xpm"
# define PLAYER_DOWN_SPRITE "assets/sprites/player/down.xpm"
# define PLAYER_LEFT_SPRITE "assets/sprites/player/left.xpm"
# define PLAYER_RIGHT_SPRITE "assets/sprites/player/right.xpm"

#define WALL '1'
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
	int width;
	int height;
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
	t_map map;
	t_player player;
	int collectibles;
} t_game;


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

// Game functions
int game_init(t_game *game);
void render_tile(t_game *game);

// Free functions
void free_map(char **layout);

#endif
