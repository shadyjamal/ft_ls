#include "ft_ls.h"

void        get_time(time_t *times, long *timens, struct stat buf, int *flag)
{
    if ((*flag & LS_u))
    {
        *times = buf.st_atimespec.tv_sec;
        *timens = buf.st_atimespec.tv_nsec;
    }
    else if (*flag & LS_upu)
    {
        *times = buf.st_birthtimespec.tv_sec;
        *timens = buf.st_birthtimespec.tv_nsec;
    }
    else
    {
        *times = buf.st_mtimespec.tv_sec;
        *timens = buf.st_mtimespec.tv_nsec;
    }  
}

t_file      *newnode(char *name, char *path, int *flag)
{
    t_file      *node;
    struct stat buf;

    if (!(node = (t_file*)malloc(sizeof(t_file))) || !(node->name = ft_strdup(name)))
        return (0); // malloc error
    if (!(node->path = ft_strjoin(path, name)))
        return (0);
    lstat(node->path, &buf); // check error & errno
    node->st_blocks = buf.st_blocks;
    node->st_gid = buf.st_gid;
    node->st_mode = buf.st_mode;
    node->st_nlink = buf.st_nlink;
    node->st_rdev = buf.st_rdev;
    node->st_size = buf.st_size;
    node->st_uid = buf.st_uid;
    get_time(&node->time_s, &node->time_ns, buf, flag);
    node->next = NULL;
    return (node);
}

void    getdata(t_file **files, char *name, char *path, int *flag)
{
    t_file  *list;

    list = *files;

    if (list)
    {
        while (list->next)
            list = list->next;
        list->next = newnode(name, path, flag);
    }
    else
        *files = newnode(name, path, flag);
}