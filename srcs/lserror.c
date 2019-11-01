#include "ft_ls.h"

void    print_error(char *content)
{
    write(2, "ft_ls: ", 7);
    ft_putstr_fd(content, 2);
    ft_putendl_fd(": No such file or directory", 2);
}