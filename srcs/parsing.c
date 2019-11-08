#include "ft_ls.h"

int     is_flag(char *str)
{
    if (str && str[0] == '-' && str[1])
        return (1);
    return (0);
}


int     get_index(char *str, char c)
{
    int i;

    i = -1;
    while (str[++i])
        if (str[i] == c)
            return (i);
    return (-1);
}

int    get_flags(int *flag, char *str)
{
    int i;
    int n;

    n = 0;
    i = 0;
    while (str[++i])
    {
        if ((n = get_index("alrRtuU",str[i])) == -1)
        {
            print_error(str + i, USAGE);
            return (-1);    // usage ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...] error function
        }
        *flag |= (1 << n);   
    }
    return (1);
}

void    parse_arg(int ac, char **av, int *flag, t_list **begin)
{
    int i;
    int j;
    
    j = -1;
    i = 0;
    while (++i < ac)
    {
        if (ft_strcmp(av[i], "--") == 0)
        {
            i += 1;
            break;
        }
        if (!is_flag(av[i]))
            break;
        get_flags(flag, av[i]);
    }
    ft_sort_tab((av += i), (ac -= i));
    while (av[++j])
            ft_lstpushback(begin, av[j], strlen(av[j]) + 1);
    //printlst(*begin); // debug
}