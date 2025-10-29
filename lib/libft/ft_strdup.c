/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loda-sil <loda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 09:36:56 by loda-sil          #+#    #+#             */
/*   Updated: 2025/09/03 18:10:09 by loda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;

	str = (char *)ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s, ft_strlen(s) + 1);
	return (str);
}
