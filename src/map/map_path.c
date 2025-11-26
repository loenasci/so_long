/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loda-sil <loda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 23:23:53 by loena             #+#    #+#             */
/*   Updated: 2025/11/14 18:32:20 by loda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static char	**map_copy_layout(char **layout, int height)
{
	char	**copy;
	int		i;

	copy = ft_calloc(sizeof(char *), height + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(layout[i]);
		if (!copy[i])
		{
			free_map(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

static void	explore_paths(t_path_data *data, int x, int y)
{
	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return ;
	if (data->map[y][x] == WALL || data->map[y][x] == 'V')
		return ;
	if (data->map[y][x] == COLLECT)
		(*data->collect_count)--;
	else if (data->map[y][x] == EXIT)
		(*data->exit_count)--;
	data->map[y][x] = 'V';
	explore_paths(data, x + 1, y);
	explore_paths(data, x - 1, y);
	explore_paths(data, x, y + 1);
	explore_paths(data, x, y - 1);
}

int	map_has_valid_path(t_game *game)
{
	t_path_data	data;
	int			collect_count;
	int			exit_count;

	data.map = map_copy_layout(game->map.layout, game->map.height);
	if (!data.map)
		return (message_error("Failed to allocate map copy!"));
	collect_count = map_count_element(game->map.layout, COLLECT);
	exit_count = 1;
	data.collect_count = &collect_count;
	data.exit_count = &exit_count;
	data.width = game->map.width;
	data.height = game->map.height;
	explore_paths(&data, game->player.x, game->player.y);
	free_map(data.map);
	if (collect_count != 0 || exit_count != 0)
		return (message_error("Map has no valid path!"));
	return (1);
}
