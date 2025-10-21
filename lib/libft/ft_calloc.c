/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loda-sil <loda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 22:19:17 by loena             #+#    #+#             */
/*   Updated: 2025/08/07 16:20:36 by loda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			total;

	if (!size)
		return (ft_strdup(""));
	if (nmemb != 0 && size > (size_t)-1 / nmemb)
		return (NULL);
	total = nmemb * size;
	ptr = (unsigned char *)malloc(total);
	if (!ptr)
		return (NULL);
	while (total--)
		ptr[total] = '\0';
	return (ptr);
}
