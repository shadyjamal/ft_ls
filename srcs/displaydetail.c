#include "ft_ls.h"

void	ft_printperms(t_file *node)
{
    ft_putchar(S_ISFIFO(node->st_mode) ? 'p' : '\0');
    ft_putchar((S_ISCHR(node->st_mode)) ? 'c' : '\0');
    ft_putchar(S_ISLNK(node->st_mode) ? 'l' : '\0');
    ft_putchar(S_ISREG(node->st_mode) ? '-' : '\0');
    ft_putchar(S_ISDIR(node->st_mode) ? 'd' : '\0');
    ft_putchar(S_ISSOCK(node->st_mode) ? 's' : '\0');
    ft_putchar((S_ISBLK(node->st_mode)) ? 'b' : '\0');
    ft_putchar((node->st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((node->st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((node->st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((node->st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((node->st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((node->st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((node->st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((node->st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((node->st_mode & S_IXOTH) ? 'x' : '-');
	ft_putstr("  ");
}

void	ft_print_int(int nb, int size)
{
	int sp;

	sp = size - ft_intlen(nb);
	while (sp--)
		ft_putchar(' ');
	ft_putnbr(nb);
	ft_putstr(" ");
}

void	ft_print_str(char *str, int size)
{
	int sp;

	sp = size - ft_strlen(str);
	ft_putstr(str);
	while (sp--)
		ft_putchar(' ');
	ft_putstr("  ");
}