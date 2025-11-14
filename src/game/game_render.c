/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loena <loena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:49:27 by loena             #+#    #+#             */
/*   Updated: 2025/11/13 19:22:17 by loena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void render_map(t_game *game, char tile, int x, int y)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
		game->map.floor.img, x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (tile == WALL)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->map.wall.img, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (tile == COLLECT)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->map.collect.img, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (tile == EXIT)
	{
		if (game->collectibles == 0)
			mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
				game->map.open_exit.img, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else
			mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
				game->map.exit.img, x * SPRITE_SIZE, y * SPRITE_SIZE);
	}
}

static void render_player(t_game *game)
{
	int px;
	int py;

	px = game->player.x * SPRITE_SIZE;
	py = game->player.y * SPRITE_SIZE;
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
		game->player.sprite[game->player.direction].img, px, py);
}

void render_tile(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			render_map(game, game->map.layout[y][x], x, y);
			x++;
		}
		y++;
	}
	render_player(game);
}
