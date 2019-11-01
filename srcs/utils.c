#include "ft_ls.h"

int		ft_sort_tab(char **tab, int size)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	while (j < size)
	{
		i = j - 1;
		tmp = (tab)[j];
		while (i >= 0 && ft_strcmp(tab[i], tmp) > 0)
		{
			tab[i + 1] = tab[i];
			i--;
		}
		tab[i + 1] = tmp;
		j++;
	}
	return (1);
}

//void	ft_sort_list()