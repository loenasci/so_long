/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loena <loena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:59:27 by loda-sil          #+#    #+#             */
/*   Updated: 2025/11/13 19:30:33 by loena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_game game;

	if (argc != 2)
		return (exit_error("invalid number of parameters!\n Use: ./program <map_path>"));
	ft_bzero(&game, sizeof(t_game));
	if (!map_check_extension(argv[1], ".ber"))
		return (exit_error("Invalid file extension! Use .ber"));
	if (!map_read(&game, argv[1]) || !map_check(&game))
	{
		free_map(game.map.layout);
		return (exit_error("Invalid map!"));
	}
	game_init(&game);
	render_tile(&game);
	free_map(game.map.layout);
	mlx_loop(game.mlx.mlx);
	return (0);
}
