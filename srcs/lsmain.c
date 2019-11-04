#include "ft_ls.h"

t_file    *storedata(t_list *file, int *flag)
{
    t_list  *cur;
    t_file  *list;

    list = NULL;
    cur = file;
    while (cur)
    {
        getdata(&list, cur->content, "", flag);
        cur = cur->next; 
    }
    printf("FLAG = %d\n", *flag);
    //printlstfile(list);
    return (list);
}

void    ls_directories(t_list *dir, int *flag)
{
    t_file          *listdir;
    t_file          *cur;
    t_file          *listfiles;    
    DIR             *op;
    struct dirent   *entry;
    
    listfiles = NULL;
    listdir = storedata(dir, flag);

    ft_sortlst(&listdir, flag);
    cur = listdir;
    while (cur)
    {
        op = opendir(cur->name);
        while ((entry = readdir(op)))
            getdata(&listfiles, entry->d_name, ft_strjoin(cur->path, "/"), flag);
        (void)closedir(op);
        printlstfile(listfiles);
        dir_name(cur->name); // display dirname only if "> 1" of (dirs) or (dirs + files) 
        ft_display(listfiles, flag);
        freelst(&listfiles); // free listfiles before using it in the next dir
        cur = cur->next;
    }
}

void        ls_files(t_list *file, int *flag)
{
    t_file  *list;

    list = storedata(file, flag);
    ft_display(list, flag);
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