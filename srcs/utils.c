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
void	freenode(t_file *node)
{
	ft_strdel(&node->name);
	ft_strdel(&node->path);
	// free(node->st_blocks);
	// free(node->st_gid);
	// free(node->st_mode);
	// free(node->st_nlink);
	// free(node->st_rdev);
	// free(node->st_size);
	// free(node->st_uid);
}
void	freelst(t_file **begin)
{
	t_file	*cur;

	cur = *begin;
	while (cur)
	{
		freenode(cur);
		cur = cur->next;
	}
	*begin = NULL;
}
// void	ft_sort_list()