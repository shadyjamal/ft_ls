/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 09:02:19 by cjamal            #+#    #+#             */
/*   Updated: 2019/04/07 21:36:50 by cjamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	nb;

	sign = 1;
	if (!(*str >= 0 && *str <= 127))
		return (0);
	while (*str <= 32 && *str != 27 && *str)
		str++;
	(((*str == '-' || *str == '+') && (*str++ == '-')) ? (sign = -1) : 1);
	nb = 0;
	while (*str >= '0' && *str <= '9')
		if ((nb = 10 * nb + (*str++ - 48)) < 0)
			return ((sign == 1 ? -1 : 0));
	return (nb * sign);
}
