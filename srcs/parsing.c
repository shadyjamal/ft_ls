/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjamal <cjamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:31:10 by cjamal            #+#    #+#             */
/*   Updated: 2019/11/12 13:15:36 by cjamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_flag(char *str)
{
	if (str && str[0] == '-' && str[1])
		return (1);
	return (0);
}

int		get_index(char *str, char c)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}

int		get_flags(int *flag, char *str)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (str[++i])
	{
		if ((n = get_index("alrRtuUG", str[i])) == -1)
			print_error(str + i, USAGE);
		if (n == 5 && (*flag & LS_UPU))
			*flag &= ~LS_UPU;
		if (n == 6 && (*flag & LS_U))
			*flag &= ~LS_U;
		*flag |= (1 << n);
	}
	return (1);
}

void	parse_arg(int ac, char **av, int *flag, t_list **begin)
{
	int i;
	int j;

	j = -1;
	i = 0;
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "--") == 0)
		{
			i += 1;
			break ;
		}
		if (!is_flag(av[i]))
			break ;
		get_flags(flag, av[i]);
	}
	ft_sort_tab((av += i), (ac -= i));
	while (av[++j])
		ft_lstpushback(begin, av[j], ft_strlen(av[j]) + 1);
}
