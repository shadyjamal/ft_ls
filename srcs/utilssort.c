/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilssort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjamal <cjamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:57:43 by cjamal            #+#    #+#             */
/*   Updated: 2019/11/12 13:18:52 by cjamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_strcmpnode(t_file *a, t_file *b)
{
	return (ft_strcmp(a->name, b->name));
}

int			ft_strrevcmpnode(t_file *a, t_file *b)
{
	return (ft_strcmp(b->name, a->name));
}

static int	ft_timecmp(t_file *a, t_file *b)
{
	if (a->time_s > b->time_s)
		return (-1);
	if (a->time_s == b->time_s)
		return (ft_strcmp(a->name, b->name));
	return (1);
}

static int	ft_revtimecmp(t_file *a, t_file *b)
{
	if (a->time_s > b->time_s)
		return (1);
	if (a->time_s == b->time_s)
		return (ft_strcmp(b->name, a->name));
	return (-1);
}

void		ft_sortlst(t_file **head, int *flag)
{
	if ((*flag & LS_R))
		ft_mergesortlst(head, &ft_strrevcmpnode);
	else
		ft_mergesortlst(head, &ft_strcmpnode);
	if ((*flag & LS_T) && (*flag & LS_R))
		ft_mergesortlst(head, &ft_revtimecmp);
	else if ((*flag & LS_T))
		ft_mergesortlst(head, &ft_timecmp);
}
