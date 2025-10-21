/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loda-sil <loda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:30:18 by loda-sil          #+#    #+#             */
/*   Updated: 2025/08/05 16:07:32 by loda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	unsigned const char	*ptr_src;

	if (n == 0 || (!dest && !src))
		return (dest);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned const char *)src;
	while (n--)
		*ptr_dest++ = *ptr_src++;
	return (dest);
}
