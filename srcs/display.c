/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjamal <cjamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:10:40 by cjamal            #+#    #+#             */
/*   Updated: 2019/11/12 13:58:16 by cjamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_displayl(t_file *lst, char perm[11], t_size size, int *flag)
{
	ft_getperms(perm, lst->st_mode);
	ft_putstr(perm);
	write(1, "  ", 2);
	ft_print_int(lst->st_nlink, size.snlink);
	ft_print_str(getpwuid(lst->st_uid)->pw_name, size.susrname);
	ft_print_str(getgrgid(lst->st_gid)->gr_name, size.sgrname);
	if (perm[0] != 'c' && perm[0] != 'b')
		ft_print_int(lst->st_size, size.ssize);
	else
		ft_print_majmin(lst, size);
	print_date(lst->time_s);
	(*flag & LS_UPG) ? ft_color(perm) : NULL;
	ft_putstr(lst->name);
	(*flag & LS_UPG) ? ft_putstr(C_RESET) : NULL;
}

static void	ft_long_display(t_file *list, int *flag, _Bool fileordir)
{
	t_size			size;
	int				blocks;
	char			perm[11];
	char			buf[NAME_MAX];

	blocks = 0;
	size = ft_getsize(list, &blocks);
	if (fileordir && list)
	{
		ft_putstr("total ");
		ft_putnbr(blocks);
		ft_putchar('\n');
	}
	while (list)
	{
		ft_displayl(list, perm, size, flag);
		if (perm[0] == 'l')
			display_lnk(list, buf);
		write(1, "\n", 1);
		list = list->next;
	}
}

static void	rec_display(t_file *list, int *flag)
{
	DIR				*op;
	t_file			*files;
	struct dirent	*en;

	files = NULL;
	en = NULL;
	op = NULL;
	dir_name(list->path, 0);
	if ((op = opendir(list->path)))
	{
		while ((en = readdir(op)))
			if (!(!(*flag & LS_A) && en->d_name[0] == '.'))
				getdata(&files, en->d_name, ft_strjoin(list->path, "/"), flag);
		op ? closedir(op) : 0;
		do_lsdir(files, flag);
	}
	else
		print_error(list->name, ERRNO);
}

static void	ft_recursivedisplay(t_file *list, int *flag)
{
	t_file			*cur;

	cur = list;
	while (cur)
	{
		if (S_ISDIR(cur->st_mode) &&
				ft_strcmp(".", cur->name) && ft_strcmp("..", cur->name))
			rec_display(cur, flag);
		cur = cur->next;
	}
}

void		ft_display(t_file *list, int *flag, _Bool fileordir)
{
	((*flag & LS_L)) ? ft_long_display(list, flag, fileordir) :
									ft_simple_display(list, flag);
	((*flag & LS_UPR)) ? ft_recursivedisplay(list, flag) : NULL;
}
