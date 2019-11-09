#include "ft_ls.h"

int main(int ac, char **av)
{
    int flag;
    int multidir;
    t_list *begin;

    multidir = 0;
    begin = NULL;
    parse_arg(ac, av, &flag, &begin);
    if (begin)
        begin->next ? (multidir = 1) : 0;
    else
        ft_lstpushback(&begin, ".", 2);
    ls_main(begin, &flag, multidir);
    ft_lstdel(&begin, &ft_bzero);
	return (0);
}