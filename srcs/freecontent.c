#include "ft_ls.h"

void	freenode(t_file *node)
{
	ft_strdel(&node->name);
	ft_strdel(&node->path);
	free(node);
}

void	freecontent(void *content, size_t contentsize)
{
	ft_bzero(content, contentsize);
	free(content);
}

void	freelst(t_file **begin)
{
	t_file *tmp;

	tmp = NULL;
	while (*begin)
	{
		tmp = (*begin)->next;
		freenode(*begin);
		*begin = tmp;
	}
}
