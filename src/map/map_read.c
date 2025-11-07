/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loda-sil <loda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:00:04 by loda-sil          #+#    #+#             */
/*   Updated: 2025/11/07 19:13:30 by loda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int map_open_file(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (menssage_error());
	
}

void	map_read(t_game *game, char *map_load)
{
	int fd;
	char *line;

	fd = open(map_load, O_RDONLY);
	if (fd == -1)
		return (1);
	map = ;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		
	}
}
