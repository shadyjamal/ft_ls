#include "ft_ls.h"

static void    ft_simple_display(t_file *list, int *flag)
{
    while (list)
    {
        if (!(!(*flag & LS_a) && list->name[0] == '.'))
            ft_putendl(list->name);
        list = list->next;        
    }
}

void    dir_name(char *dirname)
{
    write(1,"\n",1);
    ft_putstr(dirname);
    write(1,":\n",2);      
}

void    ft_display(t_file *list, int *flag)
{
    //sort list of files depending on flag
    // ((*flag & LS_r)) sort by reverse ascii
    // ((*flag & LS_t)) sort by last time modified
    // ((*flag & LS_t) && ((*flag & LS_r))) sort by reverse last time modified
    ((*flag & LS_l)) ?  /*ft_long_display*/ft_simple_display(list, flag) : ft_simple_display(list, flag);

}