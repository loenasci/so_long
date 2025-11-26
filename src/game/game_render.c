/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loda-sil <loda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:49:27 by loena             #+#    #+#             */
/*   Updated: 2025/11/14 18:35:08 by loda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	render_map(t_game *game, char tile, int x, int y)
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

static void	render_player(t_game *game)
{
	int	px;
	int	py;

	px = game->player.x * SPRITE_SIZE;
	py = game->player.y * SPRITE_SIZE;
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
		game->player.sprite[game->player.direction].img, px, py);
}

void	render_tile(t_game *game)
{
	int		x;
	int		y;
	char	*steps_str;

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
	steps_str = ft_itoa(game->player.steps);
	mlx_string_put(game->mlx.mlx, game->mlx.win, 10, 20, 0xFFFFFF, "Steps: ");
	mlx_string_put(game->mlx.mlx, game->mlx.win, 50, 20, 0x00FF00, steps_str);
	free(steps_str);
	render_player(game);
}
