/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freecontent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:21:09 by cjamal            #+#    #+#             */
/*   Updated: 2019/11/12 12:21:11 by cjamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	freenode(t_file *node)
{
	ft_strdel(&node->name);
	ft_strdel(&node->path);
	free(node);
}

void	freecontent(void *content, size_t contentsize)
{
	ft_bzero(content, contentsize);
	free(content);
}

void	freelst(t_file **begin)
{
	t_file *tmp;

	tmp = NULL;
	while (*begin)
	{
		tmp = (*begin)->next;
		freenode(*begin);
		*begin = tmp;
	}
}
