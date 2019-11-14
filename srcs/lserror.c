/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lserror.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:25:19 by cjamal            #+#    #+#             */
/*   Updated: 2019/11/12 13:11:16 by cjamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_error(char *content, int error)
{
	if (error == ERRNO)
	{
		write(2, "ft_ls: ", 7);
		ft_putstr_fd(content, 2);
		write(2, ": ", 2);
	}
	if (error == ERRNO)
		ft_putendl_fd(strerror(errno), 2);
	else if (error == USAGE)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(*content, 2);
		ft_putchar('\n');
		ft_putendl_fd("usage: ./ft_ls [-GRUalrtu] [file ...]", 2);
	}
	if (error == MALERROR || error == USAGE)
		exit(EXIT_FAILURE);
}
