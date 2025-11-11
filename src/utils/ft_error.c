/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loda-sil <loda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:05:55 by loda-sil          #+#    #+#             */
/*   Updated: 2025/11/11 10:46:28 by loda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	message_error(char *message)
{
	ft_printf("Error: %s\n", message);
	return (0);
}

int exit_error(char *message)
{
	ft_printf("Error: %s\n", message);
	return (1);
}
