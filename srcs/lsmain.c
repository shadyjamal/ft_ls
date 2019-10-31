#include "ft_ls.h"

void    ls_directories(t_list *dir, int *flag)
{
    t_list          *cur;
    t_file          *list;
    DIR             *op;
    struct dirent   *entry;
    
    list = NULL;
    cur = dir;
    printf("FLAG = %d\n", *flag);
    while (cur)
    {
        op = opendir(cur->content);
        while ((entry = readdir(op)))
            getdata(&list, entry->d_name, ft_strjoin(cur->content,"/"));
        (void)closedir(op);
        ft_displaydir(cur->content, list);
        cur = cur->next;
    }
}
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
    //printlstfile(list);
    printf("FLAG = %d\n", *flag);
    ft_simple_display(list);
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
                             print_error(cur->content);/// error errno 2
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
        ls_directories(directory, flag);
}    