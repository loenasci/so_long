/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loda-sil <loda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:00:04 by loda-sil          #+#    #+#             */
/*   Updated: 2025/11/10 17:03:01 by loda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	map_calculate_dimensions(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.layout[i])
		i++;
	game->map.height = i;
	if (i > 0)
		game->map.width = ft_strlen(game->map.layout[0]);
}

static int map_read_lines(int *fd, char **map)
{
	char *line;
	char *temp;
	
	while (1)
	{
		line = get_next_line(*fd);
		if (!line)
			break ;
		temp = ft_strjoin(*map, line);
		free(line);
		if (!temp)
		{
			free(*map);
			return (message_error("Memory allocation failed!"));
		}
		free(*map);
		*map = temp;
	}
	return (1);
}

int	map_read(t_game *game, char *map_path)
{
	int		fd;
	char	*map;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (message_error("Cannot open map!"));
	map = ft_strdup("");
	if (!map)
	{
		close(fd);
		return (message_error("Memory allocation failed!"));
	}
	if (!map_read_lines(&fd, &map))
	{
		close(fd);
		return (message_error("Memory allocation failed!"));
	}
	game->map.layout = ft_split(map, '\n');
	free(map);
	close(fd);
	if (!game->map.layout)
		return (message_error("Cannot parse map!"));
	map_calculate_dimensions(game);
	return (1);
}
