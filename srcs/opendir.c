#include "../includes/ft_ls.h"

int	ft_typeoffile(mode_t st_mode)
{
    if ((S_IFIFO & st_mode))
        return (1);
	if ((S_IFCHR  & st_mode))
        return (1);
	if ((S_IFDIR & st_mode))
        return (1);
	if ((S_IFBLK  & st_mode))
        return (1);
	if ((S_IFSOCK & st_mode))
        return (1);
    if ((S_IFREG & st_mode))
        return (2);
    if ((S_IFLNK & st_mode))
        return (3);
    return (0);
}
/*void	lstdiradd(t_lstdir **node)
{

}*/
t_lstdir	lsdirnwew(struct stat *buf)
{
	t_lstdir *node;

	if ((node = (t_lstdir*)malloc(sizeof(t_lstdir))))
	{
		//node->dirname = ;
		//node->user = ;
		//node->group = ;
		
	}

}
int main(int ac, char **av)
{
	int 		i;
	struct stat	buf;
	/*DIR *op;
	struct dirent *entry;
	struct stat buf;

	op = opendir(av[1]);
	while ((entry = readdir(op)))
	{
		printf("%s\n", entry->d_name);
	}
	(void)closedir(op);*/

	// Check Flag
	i = 1;
	while (av[i])
	{
		if (stat(av[i], &buf) == 0)
		{
			if (S_IFDIR & buf.st_mode)
			{
				// av[i] is a directory
				// add node to DIR List 
			}
			else if (!ft_typeoffile(buf.st_mode))
			{
				// av[i] is a reg file or a link
				// add node to File_list
			}
		}
	}
	return (0);
}
