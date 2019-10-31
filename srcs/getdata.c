#include "ft_ls.h"
// char			*name;
// 	char			*path;
// 	time_t			date;
// 	mode_t			st_mode;
// 	nlink_t			st_nlink;
// 	uid_t			st_uid;
// 	gid_t			st_gid;
// 	off_t			st_size;
// 	quad_t			st_blocks;
// 	dev_t			st_rdev;
// 	struct s_elem	*next;

t_file      *newnode(char *name, char *path)
{
    t_file      *node;
    struct stat buf;

    if (!(node = (t_file*)malloc(sizeof(t_file))) || !(node->name = ft_strdup(name)))
        printf("mall error"); // malloc error
    node->path = ft_strjoin(path, name);
    lstat(node->path, &buf); // check errno
    node->st_blocks = buf.st_blocks;
    node->st_gid = buf.st_gid;
    node->st_mode = buf.st_mode;
    node->st_nlink = buf.st_nlink;
    node->st_rdev = buf.st_rdev;
    node->st_size = buf.st_size;
    node->st_uid = buf.st_uid;
    node->next = NULL;
    return (node);
}

void    getdata(t_file **files, char *name, char *path)
{
    t_file  *list;

    list = *files;

    if (list)
    {
        while (list->next)
            list = list->next;
        list->next = newnode(name, path);
    }
    else
        *files = newnode(name, path);
}