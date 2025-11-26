/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loda-sil <loda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:59:27 by loda-sil          #+#    #+#             */
/*   Updated: 2025/11/14 18:23:50 by loda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (exit_error("invalid number of parameters! \
			\nUse: ./program <map_path>"));
	ft_bzero(&game, sizeof(t_game));
	if (!map_check_extension(argv[1], ".ber"))
		return (exit_error("Invalid file extension! Use file.ber"));
	if (!map_read(&game, argv[1])
		|| !map_check(&game)
		|| !game_init(&game)
		|| !map_has_valid_path(&game))
	{
		free_map(game.map.layout);
		return (1);
	}
	render_tile(&game);
	mlx_hook(game.mlx.win, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.mlx.win, 17, 0, handle_close, &game);
	mlx_loop(game.mlx.mlx);
	return (0);
}
