#include "ft_ls.h"

void    print_error(char *content, int error)
{
    if (error == ERRNO)
    {
            write(2, "ft_ls: ", 7);
            ft_putstr_fd(content, 2);
            write(2, ": ", 2);
    }
    if (error == ERRNO)
        ft_putendl_fd(strerror(errno), 2);
    else if (error == USAGE)
    {
        ft_putstr_fd("ft_ls: illegal option -- ", 2);
        ft_putchar_fd(*content, 2);
        putchar('\n');
        ft_putendl_fd("usage: ./ft_ls [-GRUalrtu] [file ...]", 2);
    }
    if (error == MALERROR || error == USAGE)
        exit(EXIT_FAILURE);
}