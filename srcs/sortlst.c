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
  
t_file* sortedmerge(t_file* a, t_file* b, int (*cmp)(t_file*, t_file*)) 
{ 
    t_file *result = NULL; 
  
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    if (cmp(a, b) <= 0) 
	{ 
        result = a; 
        result->next = sortedmerge(a->next, b, cmp); 
    } 
    else 
	{ 
        result = b; 
        result->next = sortedmerge(a, b->next, cmp); 
    } 
    return (result); 
} 

void splitlst(t_file* source, t_file** front, t_file** back) 
{ 
    t_file* fast; 
    t_file* slow; 

    slow = source; 
    fast = source->next; 
    while (fast != NULL)
    { 
        fast = fast->next; 
        if (fast != NULL) 
        { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
    *front = source;
    *back = slow->next; 
    slow->next = NULL; 
}

void ft_mergesortlst(t_file **headRef, int (*cmp)(t_file*, t_file*)) 
{ 
    t_file* head; 
    t_file* a; 
    t_file* b; 

    head = *headRef;
    if ((head == NULL) || (head->next == NULL))
        return ; 
    splitlst(head, &a, &b); 
    ft_mergesortlst(&a , cmp); 
    ft_mergesortlst(&b, cmp); 
    *headRef = sortedmerge(a, b, cmp); 
}
