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
    struct stat buf;

    while (begin)
    {
        stat(begin->path, &buf);
        printf("Name tfile = %s\n", begin->name);
        printf("mode = %d\n", begin->st_mode);
        printf("size = %lld\n", begin->st_size);
        printf("path = %s\n", begin->path);
        printf("mtime = %ld sec\n\n\n", buf.st_mtimespec.tv_nsec);
        begin = begin->next;
    }
}
void printsize(t_size *size)
{
    printf("Size of lnk = %d\n", size->snlink);
    printf("Size of username = %d\n", size->susrname);
    printf("Size of grname = %d\n", size->sgrname);
    printf("Size of size = %d\n", size->ssize);
    //printf("Size of lnk = %d", size->snlink);
}