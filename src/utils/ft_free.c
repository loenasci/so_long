/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loena <loena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:29:03 by loena             #+#    #+#             */
/*   Updated: 2025/11/13 16:19:28 by loena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_map(char **layout)
{
	int y;

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
void free_sprites_map()
{
	
}

void free_sprites_player()
{
	
}
