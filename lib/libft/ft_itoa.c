/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loda-sil <loda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:38:56 by loena             #+#    #+#             */
/*   Updated: 2025/08/11 14:53:02 by loda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	count_digits(int n)
{
	int			count;
	long int	nbr;

	if (n == 0)
		return (1);
	count = 0;
	nbr = n;
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			digits;

	nb = n;
	digits = count_digits(n);
	str = (char *)ft_calloc(digits + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = 48;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	digits -= 1;
	while (nb > 0)
	{
		str[digits--] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (str);
}
