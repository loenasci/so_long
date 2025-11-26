/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loda-sil <loda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:46:23 by loda-sil          #+#    #+#             */
/*   Updated: 2025/11/14 18:54:33 by loda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	is_valid_move(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
		return (0);
	if (game->map.layout[y][x] == WALL)
		return (0);
	if (game->map.layout[y][x] == EXIT && game->collectibles > 0)
		return (0);
	return (1);
}

static void	move_player(t_game *game, int new_x, int new_y)
{
	if (!is_valid_move(game, new_x, new_y))
		return ;
	if (game->map.layout[new_y][new_x] == COLLECT)
	{
		game->collectibles--;
		game->map.layout[new_y][new_x] = FLOOR;
	}
	if (game->map.layout[new_y][new_x] == EXIT && game->collectibles == 0)
	{
		ft_printf("Steps: %d\n", game->player.steps + 1);
		ft_printf("\nYOU WIN!!!\n");
		ft_printf("Total steps: %d\n", game->player.steps + 1);
		cleanup_game(game);
		exit(0);
	}
	game->player.y = new_y;
	game->player.x = new_x;
	game->player.steps++;
	ft_printf("Steps: %d\n", game->player.steps);
	render_tile(game);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
		handle_close(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->player.direction = PLAYER_UP;
		move_player(game, game->player.x, game->player.y - 1);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->player.direction = PLAYER_DOWN;
		move_player(game, game->player.x, game->player.y + 1);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->player.direction = PLAYER_LEFT;
		move_player(game, game->player.x - 1, game->player.y);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->player.direction = PLAYER_RIGHT;
		move_player(game, game->player.x + 1, game->player.y);
	}
	return (0);
}
