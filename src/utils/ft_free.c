/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loda-sil <loda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:29:03 by loena             #+#    #+#             */
/*   Updated: 2025/11/14 18:29:53 by loda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_map(char **layout)
{
	int	y;

	y = 0;
	if (!layout)
		return ;
	while (layout[y])
	{
		free(layout[y]);
		y++;
	}
	free(layout);
}

void	free_sprites_map(t_game *game)
{
	if (game->map.wall.img)
		mlx_destroy_image(game->mlx.mlx, game->map.wall.img);
	if (game->map.floor.img)
		mlx_destroy_image(game->mlx.mlx, game->map.floor.img);
	if (game->map.collect.img)
		mlx_destroy_image(game->mlx.mlx, game->map.collect.img);
	if (game->map.exit.img)
		mlx_destroy_image(game->mlx.mlx, game->map.exit.img);
	if (game->map.open_exit.img)
		mlx_destroy_image(game->mlx.mlx, game->map.open_exit.img);
}

void	free_sprites_player(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->player.sprite[i].img)
			mlx_destroy_image(game->mlx.mlx, game->player.sprite[i].img);
		i++;
	}
}
