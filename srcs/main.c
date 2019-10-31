#include "ft_ls.h"

int main(int ac, char **av)
{
    int flag;
    t_list *begin;

    begin = NULL;
    parse_arg(ac, av, &flag, &begin);
    //printf("Flag => %d\n", flag);
    //printlst(begin); // debug
    ls_main(begin, &flag);
	return (0);
}