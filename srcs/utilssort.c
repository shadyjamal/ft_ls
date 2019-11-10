#include "ft_ls.h"

static int ft_strcmpnode(t_file *a, t_file *b)
{
    return (ft_strcmp(a->name, b->name));
}
int ft_strrevcmpnode(t_file *a, t_file *b)
{
    return (ft_strcmp(b->name, a->name));
}

static int ft_timecmp(t_file *a, t_file *b)
{
    if (a->time_s > b->time_s)
        return (-1);
    if (a->time_s == b->time_s)
        return (ft_strcmp(a->name, b->name));
    return (1);
}
static int ft_revtimecmp(t_file *a, t_file *b)
{
    if (a->time_s > b->time_s)
        return (1);
     if (a->time_s == b->time_s)
        return (ft_strcmp(b->name, a->name));
    return (-1);
}
void ft_sortlst(t_file **head, int *flag)
{
    if ((*flag & LS_r))
        ft_mergesortlst(head, &ft_strrevcmpnode);
    else
        ft_mergesortlst(head, &ft_strcmpnode);
    if ((*flag & LS_t) && (*flag & LS_r))
        ft_mergesortlst(head, &ft_revtimecmp);
    else if ((*flag & LS_t))
        ft_mergesortlst(head, &ft_timecmp);
}