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

void    rec_display(t_file *list, int *flag)
{
    DIR             *op;
    t_file          *files;
    struct dirent   *entry;

    files = NULL;
    dir_name(list->path);
    op = opendir(list->path);
    while ((entry = readdir(op)))
        getdata(&files, entry->d_name, ft_strjoin(list->path, "/"), flag);
    closedir(op);
    ft_display(files, flag);
    freelst(&files);
}
void    ft_recursivedisplay(t_file *list, int *flag) 
{
    t_file  *cur;

    //printlstfile(list);
    cur = list;
    while (cur)
    {
        if (S_ISDIR(cur->st_mode) && (!(!(*flag & LS_a) && cur->name[0] == '.')) && ft_strcmp(".", cur->name) && ft_strcmp("..", cur->name))
            rec_display(cur, flag);
        cur = cur->next;
    }
}
void    ft_display(t_file *list, int *flag)
{
    //sort list of files depending on flag
    // ((*flag & LS_r)) sort by reverse ascii
    // ((*flag & LS_t)) sort by last time modified
    // ((*flag & LS_t) && ((*flag & LS_r))) sort by reverse last time modified
    ft_sortlst(&list, flag);
    ((*flag & LS_l)) ?  /*ft_long_display*/ ft_simple_display(list, flag) : ft_simple_display(list, flag);
    ((*flag & LS_upr)) ? ft_recursivedisplay(list, flag) : NULL;
}