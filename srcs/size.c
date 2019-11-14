/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:33:20 by cjamal            #+#    #+#             */
/*   Updated: 2019/11/12 12:39:50 by cjamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_getsizeofone(t_file *list, t_size *size)
{
	int		tmp;

	tmp = 0;
	size->snlink =
		((tmp = ft_intlen(list->st_nlink)) > size->snlink ? tmp : size->snlink);
	if (getpwuid(list->st_uid))
		size->susrname =
			((tmp = ft_strlen(getpwuid(list->st_uid)->pw_name)) >
			size->susrname ? tmp : size->susrname);
	if (getgrgid(list->st_gid))
		size->sgrname =
			((tmp = ft_strlen(getgrgid(list->st_gid)->gr_name)) >
			size->sgrname ? tmp : size->sgrname);
	if (!S_ISCHR(list->st_mode))
		tmp = ft_intlen(list->st_size);
	else
	{
		size->smaj =
	((tmp = ft_intlen(major(list->st_dev))) > size->smaj ? tmp : size->smaj);
		size->smin =
	((tmp = ft_intlen(minor(list->st_dev))) > size->smin ? tmp : size->smin);
		tmp = size->smaj + size->smin + 2;
	}
	size->ssize = ((tmp > size->ssize ? tmp : size->ssize));
}

t_size	ft_getsize(t_file *list, int *blocks)
{
	t_size	size;
	int		tmp;

	tmp = 0;
	ft_memset(&size, 0, sizeof(t_size));
	size.smaj = 3;
	size.smin = 3;
	while (list)
	{
		ft_getsizeofone(list, &size);
		*blocks += list->st_blocks;
		list = list->next;
	}
	size.smaj += ((tmp = size.ssize - size.smaj - size.smin - 2) > 0 ? tmp : 0);
	return (size);
}

void	display_lnk(t_file *lst, char buf[NAME_MAX])
{
	ft_bzero(buf, NAME_MAX);
	readlink(lst->path, buf, NAME_MAX);
	write(1, " -> ", 4);
	ft_putstr(buf);
}
