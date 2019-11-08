#include "ft_ls.h"

t_file    *storedata(t_list *file, int *flag)
{
    t_file  *list;

    list = NULL;
    while (file)
    {
        getdata(&list, file->content, "", flag);
        file = file->next; 
    }
    return (list);
}

void    ls_directories(t_list *dir, int *flag, int multidir, _Bool first)
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
        multidir ? dir_name(cur->name, first) : 0;
        first = 0;
        if ((op = opendir(cur->name)))
        {
            while ((entry = readdir(op)))
                if (!(!(*flag & LS_a) && entry->d_name[0] == '.'))
                    getdata(&listfiles, entry->d_name, (!ft_strchr(cur->path, '/') ? ft_strjoin(cur->path, "/") : cur->path), flag);
            (void)closedir(op);
            if (listfiles)
            {
                ft_display(listfiles, flag, 1);
                freelst(&listfiles); // free listfiles before using it in the next dir
            }
        }
        else
            print_error(cur->name, ERRNO);
        cur = cur->next;
    }
}

void        ls_files(t_list *file, int *flag, _Bool *first)
{
    t_file  *list;

    list = storedata(file, flag);
    ft_display(list, flag, 0);
    *first = 0;
}

void        ls_main(t_list *begin, int *flag, int multidir)
{
    struct stat buf;
    t_list  *files;
    t_list  *directory;
    _Bool   first;

    first = 1;
    files = NULL;
    directory = NULL;
    while (begin)
    {
        if (stat(begin->content, &buf) == -1)
            print_error(begin->content, ERRNO);
        else if (S_ISDIR(buf.st_mode))
            ft_lstpushback(&directory, begin->content, begin->content_size);
        else
            ft_lstpushback(&files, begin->content, begin->content_size);
        begin = begin->next;
    }
    files ? ls_files(files, flag, &first) : NULL;
    directory ? ls_directories(directory, flag, multidir, first) : NULL;
    //free list
}    