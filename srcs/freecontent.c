#include "ft_ls.h"

void	freenode(t_file *node)
{
	ft_strdel(&node->name);
	ft_strdel(&node->path);
}

void	freecontent(void *content, size_t contentsize)
{
	ft_bzero(content, contentsize);
	free(content);
}
void	freelst(t_file **begin)
{
	if (begin)
	{ 
		while (*begin)
		{
			freenode(*begin);
			free(*begin);
			*begin = (*begin)->next;
		}
	}
}