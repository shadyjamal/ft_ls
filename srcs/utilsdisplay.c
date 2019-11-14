/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsdisplay.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjamal <cjamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:51:53 by cjamal            #+#    #+#             */
/*   Updated: 2019/11/12 15:15:17 by cjamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	file_type(int mode)
{
	mode = (mode & S_IFMT);
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	else
		return ('-');
}

void		ft_getperms(char perm[11], int mode)
{
	perm[0] = file_type(mode);
	perm[1] = (S_IRUSR & mode) ? 'r' : '-';
	perm[2] = (S_IWUSR & mode) ? 'w' : '-';
	perm[3] = (S_IXUSR & mode) ? 'x' : '-';
	perm[4] = (S_IRGRP & mode) ? 'r' : '-';
	perm[5] = (S_IWGRP & mode) ? 'w' : '-';
	perm[6] = (S_IXGRP & mode) ? 'x' : '-';
	perm[7] = (S_IROTH & mode) ? 'r' : '-';
	perm[8] = (S_IWOTH & mode) ? 'w' : '-';
	perm[9] = (S_IXOTH & mode) ? 'x' : '-';
	perm[10] = '\0';
	if (S_ISUID & mode)
		perm[3] = perm[3] == '-' ? 'S' : 's';
	if (S_ISGID & mode)
		perm[6] = perm[6] == '-' ? 'S' : 's';
	if (S_ISVTX & mode)
		perm[9] = perm[9] == '-' ? 'T' : 't';
}

void		ft_color(char prm[11])
{
	(prm[0] == 'b') ? ft_putstr(B_CYAN) : NULL;
	(prm[0] == 'c') ? ft_putstr(B_YELLOWB) : NULL;
	if (prm[0] == 'd')
		(prm[8] != 'w' ? ft_putstr(C_CYAN) : ft_putstr(B_YELLOW));
	(prm[0] == 'f') ? ft_putstr(C_BROWN) : NULL;
	if (prm[0] == '-')
		(prm[3] != 'x' && prm[6] != 'x' && prm[9] != 'x' ?
		ft_putstr(C_RESET) : ft_putstr(C_RED));
	(prm[0] == 'l') ? ft_putstr(C_PURPLE) : NULL;
	(prm[0] == 's') ? ft_putstr(C_GREEN) : NULL;
}

void		ft_simple_display(t_file *list, int *flag)
{
	char	perm[11];

	while (list)
	{
		ft_getperms(perm, list->st_mode);
		if (!(!(*flag & LS_A) && list->name[0] == '.' &&
					!ft_strrchr(list->name, '/')))
		{
			(*flag & LS_UPG) ? ft_color(perm) : NULL;
			ft_putendl(list->name);
			(*flag & LS_UPG) ? ft_putstr(C_RESET) : NULL;
		}
		list = list->next;
	}
}

void		do_lsdir(t_file *files, int *flag)
{
	if (files)
	{
		ft_sortlst(&files, flag);
		ft_display(files, flag, 1);
		freelst(&files);
		files = NULL;
	}
}
