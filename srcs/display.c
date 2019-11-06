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

void            ft_long_display(t_file *list, int *flag)
{
    t_size  size;
    
	//print total xxx if dir
    ft_putstr("total ");
    ft_putchar('\n');
    size = ft_getsize(list);
    while (list)
    {
        if (!(!(*flag & LS_a) && list->name[0] == '.'))
            {
                //print permissions
                ft_printperms(list);
                //nb links
                ft_print_int(list->st_nlink, size.snlink);
                //print username getpwuid
                ft_print_str(getpwuid(list->st_uid)->pw_name, size.susrname);
                //print grp getgruid
                ft_print_str(getgrgid(list->st_gid)->gr_name, size.sgrname);
                //print size st_size / maj min
                ft_print_int(list->st_size, size.ssize);
                //print date 
                //print colored name file
                ft_putendl(list->name);
            } 
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
    if ((op = opendir(list->path)))
    {
        while ((entry = readdir(op)))
            getdata(&files, entry->d_name, ft_strjoin(list->path, "/"), flag);
        closedir(op);
        if (files)
        {
            ft_display(files, flag);
            freelst(&files);
        }
    }
}
void    ft_recursivedisplay(t_file *list, int *flag) 
{
    t_file  *cur;

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
    ft_sortlst(&list, flag);
    ((*flag & LS_l)) ?  ft_long_display(list, flag) : ft_simple_display(list, flag);
    ((*flag & LS_upr)) ? ft_recursivedisplay(list, flag) : NULL;
}