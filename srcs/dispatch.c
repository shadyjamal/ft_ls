#include "ft_ls.h"

void        ls_files(t_list *file, int *flag)
{
    t_list  *cur;
    t_file  *list;

    list = NULL;
    cur = file;
    while (cur)
    {
        getdata(&list, cur->content, "");
        cur = cur->next; 
    }
    printlstfile(list);
    printf("FLAG = %d\n", *flag);
    //displayfiles();
}

void        ls_main(t_list *begin, int *flag)
{
    DIR     *dir;
    t_list  *files;
    t_list  *directory;
    t_list  *cur;

    files = NULL;
    directory = NULL;
    cur = begin;
    while (cur)
    {
        if (!(dir = opendir(cur->content)))
            errno == ENOTDIR ? ft_lstpushback(&files, cur->content, cur->content_size) : \
                             printf("%s no such file errno = %d\n", cur->content, errno); // error errno 2
        else
        {
            ft_lstpushback(&directory, cur->content, cur->content_size);
            if (closedir(dir) == -1)
                printf("close error"); // close dir error // errno
        }
        cur = cur->next;
    }
    if (files)
        ls_files(files, flag);
    if (directory)
        printf("\n\nshow directories\n\n");
}    