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
  
    /* Base cases */
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    /* Pick either a or b, and recur */
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

/* Split the nodes of the given list into front and back halves, 
    and return the two lists using the reference parameters. 
    If the length is odd, the extra node should go in the front list. 
    Uses the fast/slow pointer strategy. */
void splitlst(t_file* source, t_file** front, t_file** back) 
{ 
    t_file* fast; 
    t_file* slow; 
    slow = source; 
    fast = source->next; 
  
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
    /* 'slow' is before the midpoint in the list, so split it in two 
    at that point. */
    *front = source; 
    *back = slow->next; 
    slow->next = NULL; 
}

void ft_mergesortlst(t_file **headRef, int (*cmp)(t_file*, t_file*)) 
{ 
    t_file* head = *headRef; 
    t_file* a; 
    t_file* b; 
  
    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) { 
        return; 
    } 
    /* Split head into 'a' and 'b' sublists */
    splitlst(head, &a, &b); 
    /* Recursively sort the sublists */
    ft_mergesortlst(&a , cmp); 
    ft_mergesortlst(&b, cmp); 
    /* answer = merge the two sorted lists together */
    *headRef = sortedmerge(a, b, cmp); 
}

int ft_strcmpnode(t_file *a, t_file *b)
{
    return (ft_strcmp(a->name, b->name));
}
int ft_strrevcmpnode(t_file *a, t_file *b)
{
    return (ft_strcmp(b->name, a->name));
}

int ft_timecmp(t_file *a, t_file *b)
{
    if ((a->time_s - b->time_s) > 0)
        return (1);
    else if ( (a->time_s - b->time_s) < 0)
        return (-1);
    else
        return (strcmp(a->name, b->name));
}
int ft_revtimecmp(t_file *a, t_file *b)
{
    if (b->time_s - a->time_s > 0)
        return (1);
    else if (b->time_s - a->time_s < 0)
        return (-1);
    else
        return (strcmp(b->name, a->name));
}
void ft_sortlst(t_file **head, int *flag)
{
    if ((*flag & LS_t) && (*flag & LS_r))
        ft_mergesortlst(head, &ft_revtimecmp);
    else if ((*flag & LS_t))
    {
        printf("OKOKOK");
        ft_mergesortlst(head, &ft_timecmp);
    }
    else if ((*flag & LS_r))
        ft_mergesortlst(head, &ft_strrevcmpnode);
    else
        ft_mergesortlst(head, &ft_strcmpnode);
}