/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loda-sil <loda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:39:46 by loda-sil          #+#    #+#             */
/*   Updated: 2025/11/11 14:02:55 by loda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int map_check_extension(char *filename, char *extension)
{
	int len_filename;
	int len_extension;

	if (!filename || !extension)
		return (0);

	len_filename = ft_strlen(filename);
	len_extension = ft_strlen(extension);

	if(len_filename < len_extension)
		return (0);

	if (ft_strncmp(filename + (len_filename - len_extension), extension, len_extension) == 0)
		return (1);
	return (0);
}

static int	map_check_borders(t_game *game)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < game->map.width)
	{
		if (game->map.layout[0][x] != '1' 
			|| game->map.layout[game->map.height - 1][x] != '1')
			return (message_error("Map must be surrounded by walls (1)!"));
		x++;
	}
	while (y < game->map.height)
	{
		if (game->map.layout[y][0] != '1' 
			|| game->map.layout[y][game->map.width - 1] != '1')
			return (message_error("Map must be surrounded by wall (1)!"));
		y++;
	}
	return (1);
}

static int	map_check_is_rectangular(char **layout)
{
	int y;
	int x;
	int len_first_line;
	int len_current_line;

	y = 0;
	x = 0;
	len_first_line = ft_strlen(layout[y]);
	while (layout[++y])
	{
		len_current_line = ft_strlen(layout[y]);
		if (len_first_line != len_current_line)
			return (message_error("Map must be rectangular!"));
	}
	return (1);
}

static int	map_check_elements(char **layout)
{
	int x;
	int y;
	int collect;
	int player;
	int exit;

	x = 0;
	y = 0;
	collect = map_count_element(layout, 'C');
	player = map_count_element(layout, 'P');
	exit = map_count_element(layout, 'E');
	while (layout[y])
	{
		x = 0;
		while(layout[y][x])
		{
			if (!map_is_valid_char(layout[y][x]))
				return (message_error("Invalid character in map!\n"));
			x++;
		}
		y++;
	}
	if(!map_validate_element_counts(player, collect, exit))
		return (0);
	return (1);
}

int map_check(t_game *game)
{
	if (!map_check_is_rectangular(game->map.layout))
		return (0);
	if (!map_check_elements(game->map.layout))
		return (0);
	if (!map_check_borders(game))
		return (0);
	return (1);
}
