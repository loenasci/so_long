/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loda-sil <loda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:39:46 by loda-sil          #+#    #+#             */
/*   Updated: 2025/11/10 18:27:03 by loda-sil         ###   ########.fr       */
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
