/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 09:08:10 by cjamal            #+#    #+#             */
/*   Updated: 2019/04/02 12:50:33 by cjamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1++ == *s2++ && *(s1 - 1) && *(s2 - 1) && n--)
		;
	if (!n)
		return (0);
	return (*((unsigned char*)(s1 - 1)) - *((unsigned char*)(s2 - 1)));
}