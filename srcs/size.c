#include "ft_ls.h"


t_size    ft_getsize(t_file *list, int *blocks)
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
        
        if (!S_ISCHR(list->st_mode))
            tmp = ft_intlen(list->st_size);
        else 
        {
            size.smaj = ((tmp = ft_intlen(major(list->st_rdev))) > size.smaj ? tmp : size.smaj);
            size.smin = ((tmp = ft_intlen(minor(list->st_rdev))) > size.smin ? tmp : size.smin);
            tmp = size.smaj + size.smin + 2;
        }
        size.ssize = ((tmp > size.ssize ? tmp : size.ssize));
        *blocks += list->st_blocks;
        list = list->next;
    }
    //printsize(&size);
    return (size);
} 