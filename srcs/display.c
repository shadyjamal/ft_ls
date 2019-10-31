#include "ft_ls.h"

void    print_error(char *content)
{
    write(2, "ft_ls: ", 7);
    ft_putstr_fd(content, 2);
    ft_putendl_fd(": No such file or directory", 2);
}

void    ft_simple_display(t_file *list)
{
    while (list)
    {
        ft_putendl(list->name);
        list = list->next;        
    }
}

void    ft_displaydir(char *dirname, t_file *list)
{
    write(1,"\n",1);
    ft_putstr(dirname);
    write(1,":\n",2);
    while (list)
    {
        ft_putendl(list->name);
        list = list->next;
    }      
}