#include "ft_ls.h"

void	ft_color(char prm[11])
{
	(prm[0] == 'b') ? ft_putstr(B_CYAN) : NULL;
	(prm[0] == 'c') ? ft_putstr(B_YELLOWB) : NULL;
    if (prm[0] == 'd')
        (prm[8] != 'w' ? ft_putstr(C_CYAN): ft_putstr(B_YELLOW));
	(prm[0] == 'f')? ft_putstr(C_BROWN) : NULL;
    if (prm[0] == '-')
        (prm[3] != 'x' && prm[6] != 'x' && prm[9] != 'x' ? 
        ft_putstr(C_RESET) : ft_putstr(C_RED));
    (prm[0] == 'l') ? ft_putstr(C_PURPLE) : NULL;
	(prm[0] == 's') ? ft_putstr(C_GREEN) : NULL;
}

static void    ft_simple_display(t_file *list, int *flag)
{
    char        perm[11];

    while (list)
    {
        ft_getperms(perm, list->st_mode);
        if (!(!(*flag & LS_a) && list->name[0] == '.'))
        {
            (*flag & LS_upg) ? ft_color(perm) : NULL;
            ft_putendl(list->name);
            (*flag & LS_upg) ? ft_putstr(C_RESET) : NULL;;
        }
        list = list->next;        
    }
}

void            ft_long_display(t_file *list, int *flag, _Bool fileordir)
{
    t_size      size;
    int         blocks;
    char        perm[11];
    char        buf[NAME_MAX];
    
    (void)*flag;    
    blocks = 0;
    size = ft_getsize(list, &blocks);
    if (fileordir)
    {
        ft_putstr("total ");
        ft_putnbr(blocks);
        ft_putchar('\n');
    }
    while (list)
    {
        //print permissions
        ft_getperms(perm, list->st_mode);
        ft_putstr(perm);
	    write(1, "  ", 2);
        //nb links
        ft_print_int(list->st_nlink, size.snlink);
        //print username getpwuid
        ft_print_str(getpwuid(list->st_uid)->pw_name, size.susrname);
        //print grp getgruid
        ft_print_str(getgrgid(list->st_gid)->gr_name, size.sgrname);
        //print size st_size / maj min
        if (perm[0] != 'c' && perm[0] != 'b')
            ft_print_int(list->st_size, size.ssize);
        else 
            ft_print_majmin(list, size);
        //print date
        print_date(list->time_s);
        //print colored name file // link ->
        (*flag & LS_upg) ? ft_color(perm) : NULL;
        ft_putstr(list->name);
        (*flag & LS_upg) ? ft_putstr(C_RESET) : NULL;;
        if (perm[0] == 'l')
        {
            ft_bzero(buf, NAME_MAX);
            readlink(list->path, buf, NAME_MAX);
            write(1, " -> ", 4);
            ft_putstr(buf);
        }
        write(1, "\n", 1);
        list = list->next;
    }
}

void    dir_name(char *dirname, _Bool first)
{
    if (!first)
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
    dir_name(list->path, 0);
    if ((op = opendir(list->path)))
    {
        while ((entry = readdir(op)))
            if (!(!(*flag & LS_a) && entry->d_name[0] == '.'))
                getdata(&files, entry->d_name, ft_strjoin(list->path, "/"), flag);
        closedir(op);
        if (files)
        {
            ft_display(files, flag, 1);
            freelst(&files);
        }
    }
    else
        print_error(list->name, ERRNO);
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
void    ft_display(t_file *list, int *flag, _Bool fileordir)
{
    ft_sortlst(&list, flag);
    ((*flag & LS_l)) ?  ft_long_display(list, flag, fileordir) : ft_simple_display(list, flag);
    ((*flag & LS_upr)) ? ft_recursivedisplay(list, flag) : NULL;
    
}