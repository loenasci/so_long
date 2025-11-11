/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loda-sil <loda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:59:27 by loda-sil          #+#    #+#             */
/*   Updated: 2025/11/11 14:05:11 by loda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_game game;
	
	if (argc != 2)
		return (exit_error("invalid number of parameters!\n Use: ./program <map_path>"));
	if (!map_check_extension(argv[1], ".ber"))
		return (exit_error("Invalid file extension! Use .ber"));
	if (!map_read(&game, argv[1]))
		return (exit_error("Invalid map!"));
	if (!map_check(&game))
		return (exit_error("Invalid map!"));
	return (0);
}
