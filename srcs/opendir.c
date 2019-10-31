// #include "../includes/ft_ls.h"
// #include <sys/errno.h>

// int main(int ac, char **av)
// {
// 	int 		i;
// 	DIR *op;
// 	struct dirent *entry;
// 	struct stat buf;

// 	op = opendir(av[1]);
// 	while ((entry = readdir(op)))
// 	{
// 		printf("%s\n", entry->d_name);
// 	}
// 	(void)closedir(op);

// 	i = 0;
// 	while (av[++i])
// 	{
//         (opendir(av[i])) ? printf("opened\n") : printf("not opened\n");
//         printf("ERRNO %d\n\n\n", errno);
//         printf("STAT %d\n", stat(av[i], &buf));
//         printf("LSTAT %d\n", lstat(av[i], &buf));
//         printf("ERRNO %d\n\n\n", errno);
// 	}
// 	return (0);
// }
