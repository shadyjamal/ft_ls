#include "ft_ls.h"


t_size    ft_getsize(t_file *list)
{
    t_size  size;
    int     tmp;

    tmp = 0;
    ft_memset(&size, 0, sizeof(t_size));
    while (list)
    {
        size.snlink = ((tmp = ft_intlen(list->st_nlink)) > size.snlink ? tmp : size.snlink);
        if (getpwuid(list->st_uid))
            size.susrname = ((tmp = ft_strlen(getpwuid(list->st_uid)->pw_name)) > size.susrname ? tmp : size.susrname);
        if (getgrgid(list->st_gid))
            size.sgrname = ((tmp = ft_strlen(getgrgid(list->st_gid)->gr_name)) > size.sgrname ? tmp : size.sgrname);
        size.ssize = ((tmp = ft_strlen(ft_itoa(list->st_size))) > size.ssize ? tmp : size.ssize);
        list = list->next;
    }
    //printsize(&size);
    return (size);
} 