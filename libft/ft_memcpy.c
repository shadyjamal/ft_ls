/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjamal <cjamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 09:05:17 by cjamal            #+#    #+#             */
/*   Updated: 2019/11/10 16:11:22 by cjamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t l;

	l = 0;
	while (l < n - 1)
	{
		*(unsigned char*)dst++ = *(unsigned char*)src++;
		l++;
	}
	*(unsigned char*)dst = *(unsigned char*)src;
	return (dst - n + 1);
}
