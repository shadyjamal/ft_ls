/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjamal <cjamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:25:54 by cjamal            #+#    #+#             */
/*   Updated: 2019/11/12 16:24:56 by cjamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file	*storedata(t_list *file, int *flag)
{
	t_file			*list;

	list = NULL;
	while (file)
	{
		getdata(&list, file->content, ft_strdup(""), flag);
		file = file->next;
	}
	return (list);
}

static void		ls_readdir(t_file **dir, int *flag, int multidir, _Bool first)
{
	t_file			*lstfiles;
	DIR				*op;
	struct dirent	*ent;

	lstfiles = NULL;
	ent = NULL;
	while (*dir)
	{
		multidir ? dir_name((*dir)->name, first) : 0;
		first = 0;
		if ((op = opendir((*dir)->name)))
		{
			while ((ent = readdir(op)))
				if (!(!(*flag & LS_A) && ent->d_name[0] == '.'))
					getdata(&lstfiles, ent->d_name, ft_strjoin((*dir)->path,
					ft_strcmp((*dir)->name, "/") ? "/" : ""), flag);
			op ? (void)closedir(op) : 0;
			do_lsdir(lstfiles, flag);
			lstfiles = NULL;
		}
		else
			print_error((*dir)->name, ERRNO);
		*dir = (*dir)->next;
	}
}

static void		ls_directories(t_list *dir, int *flag, int multidir, _Bool frs)
{
	t_file			*listdir;
	t_file			*cur;

	listdir = storedata(dir, flag);
	cur = listdir;
	if (cur)
	{
		ft_sortlst(&cur, flag);
		ls_readdir(&cur, flag, multidir, frs);
		freelst(&listdir);
	}
}

static void		ls_files(t_list *file, int *flag, _Bool *first)
{
	t_file			*list;

	list = NULL;
	list = storedata(file, flag);
	if (list)
	{
		ft_sortlst(&list, flag);
		ft_display(list, flag, 0);
		freelst(&list);
		*first = 0;
	}
}

void			ls_main(t_list *begin, int *flag, int multidir)
{
	struct stat		buf;
	t_list			*files;
	t_list			*directory;
	_Bool			first;

	first = 1;
	files = NULL;
	directory = NULL;
	while (begin)
	{
		if (lstat(begin->content, &buf) == -1)
			print_error(begin->content, ERRNO);
		else if (S_ISDIR(buf.st_mode) ||
				(S_ISLNK(buf.st_mode) &&
				!(*flag & LS_L) && !stat(begin->content, &buf)))
			ft_lstpushback(&directory, begin->content, begin->content_size);
		else
			ft_lstpushback(&files, begin->content, begin->content_size);
		begin = begin->next;
	}
	files ? ls_files(files, flag, &first) : NULL;
	directory ? ls_directories(directory, flag, multidir, first) : NULL;
	files ? ft_lstdel(&files, &freecontent) : 0;
	directory ? ft_lstdel(&directory, &freecontent) : 0;
}
