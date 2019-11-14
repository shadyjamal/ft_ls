/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaydetail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjamal <cjamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:18:50 by cjamal            #+#    #+#             */
/*   Updated: 2019/11/12 13:17:39 by cjamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_majmin(t_file *file, t_size size)
{
	int		min;
	int		maj;

	min = (int)ft_intlen(minor(file->st_dev));
	maj = (int)ft_intlen(major(file->st_dev));
	while (maj < size.smaj--)
		ft_putchar(' ');
	ft_putnbr(major(file->st_dev));
	ft_putstr(", ");
	while (min < size.smin--)
		ft_putchar(' ');
	ft_putnbr((int)minor(file->st_dev));
	ft_putchar(' ');
}

void	ft_print_int(int nb, int size)
{
	int sp;

	sp = size - ft_intlen(nb);
	while (sp--)
		ft_putchar(' ');
	ft_putnbr(nb);
	ft_putstr(" ");
}

void	ft_print_str(char *str, int size)
{
	int sp;

	sp = size - ft_strlen(str);
	ft_putstr(str);
	while (sp--)
		ft_putchar(' ');
	ft_putstr("  ");
}

void	print_date(time_t date)
{
	char	*str_date;
	char	*tmp;
	char	*year;
	time_t	actualtime;

	str_date = ft_strnew(13);
	tmp = ctime(&date) + 4;
	actualtime = time(0);
	if ((actualtime - 15778463) > date || actualtime < date)
	{
		year = ft_strsub(tmp, 16, 4);
		str_date = ft_strncat(str_date, tmp, 6);
		str_date = ft_strcat(str_date, "  ");
		str_date = ft_strcat(str_date, year);
		free(year);
	}
	else
		str_date = ft_strncat(str_date, tmp, 12);
	ft_putstr(str_date);
	ft_putchar(' ');
	free(str_date);
}

void	dir_name(char *dirname, _Bool first)
{
	if (!first)
		write(1, "\n", 1);
	ft_putstr(dirname);
	write(1, ":\n", 2);
}
