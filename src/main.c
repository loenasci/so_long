/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loda-sil <loda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:59:27 by loda-sil          #+#    #+#             */
/*   Updated: 2025/11/10 18:34:08 by loda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_game game;
	
	if (argc != 2)
		return (message_error("invalid number of parameters!\n Use: ./program <map_path>"));
	if (!map_check_extension(argv[1], ".ber"))
		return (message_error("Invalid file extension! Use .ber"));
	if (!map_read(&game, argv[1]))
		return (1);
	return (0);
}
