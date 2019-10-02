#include <dirent.h>
#include <stdio.h>

int main(int ac, char **av)
{
	DIR *op;
	struct dirent *entry;

	op = opendir(av[1]);
	while ((entry = readdir(op)))
	{
		printf("%s\n", entry->d_name);
	}
	(void)closedir(op);
	return (0);
}
