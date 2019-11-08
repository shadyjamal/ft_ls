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

void	ft_print_majmin(t_file *file, t_size size)
{
	int		min;
	int		maj;

	min = (int)ft_intlen(minor(file->st_rdev));
	maj = (int)ft_intlen(major(file->st_rdev));
	while (maj < size.smaj--)
		ft_putchar(' ');
	ft_putnbr(major(file->st_rdev));
	ft_putstr(", ");
	while (min < size.smin--)
		ft_putchar(' ');
	ft_putnbr(minor(file->st_rdev));
	ft_putchar(' ');
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
void	print_date(time_t date)
{
	char	*str_date;
	char	*tmp;
	char	*year;
	time_t	actualtime;

	str_date = ft_strnew(13);
	tmp = ctime(&date) + 4;
	actualtime = time(0);
	if ((actualtime - 15778463) > date || actualtime < date)
	{
		year = ft_strsub(tmp, 16, 4); // year
		str_date = ft_strncat(str_date, tmp, 6);
		str_date = ft_strcat(str_date, "  ");
		str_date = ft_strcat(str_date, year);
		free(year);
	}
	else
		str_date = ft_strncat(str_date, tmp, 12);
	ft_putstr(str_date);
	ft_putchar(' ');
	free(str_date);
}