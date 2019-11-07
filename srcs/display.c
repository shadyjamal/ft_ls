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

void	ft_color(mode_t mode)
{
	S_ISBLK(mode) ? ft_putstr(C_RED) : NULL;
	S_ISCHR(mode) ? ft_putstr(C_BLUE) : NULL;
	S_ISDIR(mode) ? ft_putstr(C_CYAN) : NULL;
	S_ISFIFO(mode) ? ft_putstr(C_BROWN) : NULL;
	S_ISREG(mode) ? ft_putstr(C_NONE) : NULL;
	S_ISLNK(mode) ? ft_putstr(C_GREEN) : NULL;
	S_ISSOCK(mode) ? ft_putstr(C_MAGENTA) : NULL;
}

void            ft_long_display(t_file *list, int *flag)
{
    t_size  size;
    int     blocks;
    
    blocks = 0;
    size = ft_getsize(list, &blocks);
    ft_putstr("total ");
    ft_putnbr(blocks);
    ft_putchar('\n');
    while (list)
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
        if (!S_ISCHR(list->st_mode) && !S_ISBLK(list->st_mode))
            ft_print_int(list->st_size, size.ssize);
        else 
            ft_print_majmin(list, size);
        //print date
        print_date(list->time_s);
        //print colored name file // link ->
        ft_color(list->st_mode);
        ft_putendl(list->name);
        ft_putstr(C_NONE);
        list = list->next;
    }
    ft_putnbr(*flag);
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
            if (!(!(*flag & LS_a) && entry->d_name[0] == '.'))
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
        if (S_ISDIR(cur->st_mode) && ft_strcmp(".", cur->name) && ft_strcmp("..", cur->name))
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