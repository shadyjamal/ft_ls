#include "ft_ls.h"

void	freenode(t_file *node)
{
	ft_strdel(&node->name);
	ft_strdel(&node->path);
}
void	freelst(t_file **begin)
{
	t_file	*cur;

	cur = *begin;
	while (cur)
	{
		freenode(cur);
		free(cur);
		cur = cur->next;
	}
	*begin = NULL;
}