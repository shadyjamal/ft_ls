/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:30:26 by cjamal            #+#    #+#             */
/*   Updated: 2019/11/12 12:30:53 by cjamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int ac, char **av)
{
	int		flag;
	int		multidir;
	t_list	*begin;

	flag = 0;
	multidir = 0;
	begin = NULL;
	parse_arg(ac, av, &flag, &begin);
	if (begin)
		begin->next ? (multidir = 1) : 0;
	else
		ft_lstpushback(&begin, ".", 2);
	ls_main(begin, &flag, multidir);
	ft_lstdel(&begin, &freecontent);
	return (0);
}
