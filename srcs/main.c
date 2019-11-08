#include "ft_ls.h"

int main(int ac, char **av)
{
    int flag;
    int multidir;
    t_list *begin;

    multidir = 1;
    begin = NULL;
    parse_arg(ac, av, &flag, &begin);
    //printf("Flag => %d\n", flag);
    //printlst(begin); // debug
    !begin->next ? (multidir = 0) : 0 ; 
    ls_main(begin, &flag, multidir);
	return (0);
}