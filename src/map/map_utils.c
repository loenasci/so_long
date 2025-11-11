/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loda-sil <loda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:28:08 by loda-sil          #+#    #+#             */
/*   Updated: 2025/11/11 12:50:33 by loda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int map_is_valid_char(char c)
{
	if (c != '0' && c != '1' && c != 'P' && c != 'C' && c != 'E')
		return (0);
	return (1);
}

int map_count_element(char **layout, char element)
{
	int y;
	int x;
	int count;

	y = 0;
	x = 0;
	count = 0;
	while (layout[y])
	{
		x = 0;
		while (layout[y][x])
		{
			if (layout[y][x] == element)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
int	map_validate_element_counts(int player, int collect, int exit)
{
	if (player != 1)
		return (message_error("Map must have 1 player (P)!"));
	if (collect < 1)
		return (message_error("Map must have at least 1 collectible (C)!"));
	if (exit != 1)
		return (message_error("Map must have 1 exit (E)!"));
	return (1);
}
