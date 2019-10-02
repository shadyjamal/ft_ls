/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 09:04:11 by cjamal            #+#    #+#             */
/*   Updated: 2019/03/30 09:04:12 by cjamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *nav;

	if (alst && del)
	{
		nav = *alst;
		while (nav)
		{
			del((nav)->content, (nav)->content_size);
			free(nav);
			nav = nav->next;
		}
		*alst = NULL;
	}
}
