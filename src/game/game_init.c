/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loda-sil <loda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:36:49 by loena             #+#    #+#             */
/*   Updated: 2025/11/14 15:01:41 by loda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	game_find_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.layout[y][x] == PLAYER)
			{
				game->player.y = y;
				game->player.x = x;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (message_error("Player not found!"));
}

static int	game_load_sprites_map(t_game *game)
{
	game->map.wall.img = mlx_xpm_file_to_image(game->mlx.mlx, WALL_SPRITE,
			&game->map.wall.width,
			&game->map.wall.height);
	game->map.floor.img = mlx_xpm_file_to_image(game->mlx.mlx, FLOOR_SPRITE,
			&game->map.floor.width,
			&game->map.floor.height);
	game->map.collect.img = mlx_xpm_file_to_image(game->mlx.mlx,
			COLLECT_SPRITE,
			&game->map.collect.width,
			&game->map.collect.height);
	game->map.exit.img = mlx_xpm_file_to_image(game->mlx.mlx, EXIT_SPRITE,
			&game->map.exit.width,
			&game->map.exit.height);
	game->map.open_exit.img = mlx_xpm_file_to_image(game->mlx.mlx,
			OPEN_EXIT_SPRITE,
			&game->map.open_exit.width,
			&game->map.open_exit.height);
	if (!game->map.wall.img
		|| !game->map.floor.img
		|| !game->map.collect.img
		|| !game->map.exit.img
		|| !game->map.open_exit.img)
		return (message_error("Failed to load map sprites!"));
	return (1);
}

static int	game_load_sprites_player(t_game *game)
{
	game->player.sprite[PLAYER_UP].img = mlx_xpm_file_to_image(game->mlx.mlx,
			PLAYER_UP_SPRITE,
			&game->player.sprite[PLAYER_UP].width,
			&game->player.sprite[PLAYER_UP].height);
	game->player.sprite[PLAYER_DOWN].img = mlx_xpm_file_to_image(game->mlx.mlx,
			PLAYER_DOWN_SPRITE,
			&game->player.sprite[PLAYER_DOWN].width,
			&game->player.sprite[PLAYER_DOWN].height);
	game->player.sprite[PLAYER_LEFT].img = mlx_xpm_file_to_image(game->mlx.mlx,
			PLAYER_LEFT_SPRITE,
			&game->player.sprite[PLAYER_LEFT].width,
			&game->player.sprite[PLAYER_LEFT].height);
	game->player.sprite[PLAYER_RIGHT].img = mlx_xpm_file_to_image(
			game->mlx.mlx,
			PLAYER_RIGHT_SPRITE,
			&game->player.sprite[PLAYER_RIGHT].width,
			&game->player.sprite[PLAYER_RIGHT].height);
	if (!game->player.sprite[PLAYER_UP].img
		|| !game->player.sprite[PLAYER_DOWN].img
		|| !game->player.sprite[PLAYER_LEFT].img
		|| !game->player.sprite[PLAYER_RIGHT].img)
		return (message_error("Failed to load player sprites!"));
	return (1);
}

int	game_init(t_game *game)
{
	if (!game_find_player(game))
		return (0);
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		return (message_error("Failed to init MLX!"));
	game->mlx.win = mlx_new_window(game->mlx.mlx,
			game->map.width * SPRITE_SIZE,
			game->map.height * SPRITE_SIZE, "so long");
	if (!game->mlx.win)
	{
		cleanup_game(game);
		return (message_error("Failed to create window!"));
	}
	if (!game_load_sprites_map(game) || !game_load_sprites_player(game))
	{
		cleanup_game(game);
		return (0);
	}
	game->collectibles = map_count_element(game->map.layout, COLLECT);
	game->player.direction = PLAYER_RIGHT;
	game->player.steps = 0;
	return (1);
}
