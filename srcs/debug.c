#include "ft_ls.h"

void printtab(char **str, int size)
{
    int i = 0;
    
    while (i < size)
    {
        printf(" TAB[%d] = %s\n", i, str[i]);
        i++;
    }
}

void printlst(t_list *begin)
{
    while (begin)
    {
        printf("Name tlist = %s\n", begin->content);
        begin = begin->next;
    }
}

void printlstfile(t_file *begin)
{
    while (begin)
    {
        printf("Name tfile = %s\n", begin->name);
        printf("mode = %d\n", begin->st_mode);
        printf("size = %lld\n", begin->st_size);
        printf("path = %s\n", begin->path);
        begin = begin->next;
    }
}