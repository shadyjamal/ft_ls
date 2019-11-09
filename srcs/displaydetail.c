#include "ft_ls.h"

static char		file_type(int mode)
{
	mode = (mode & S_IFMT);
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	else
		return ('-');
}
void	ft_getperms(char perm[11], int mode)
{
    perm[0] = file_type(mode);
	perm[1] = (S_IRUSR & mode) ? 'r' : '-';
	perm[2] = (S_IWUSR & mode) ? 'w' : '-';
	perm[3] = (S_IXUSR & mode) ? 'x' : '-';
	perm[4] = (S_IRGRP & mode) ? 'r' : '-';
	perm[5] = (S_IWGRP & mode) ? 'w' : '-';
	perm[6] = (S_IXGRP & mode) ? 'x' : '-';
	perm[7] = (S_IROTH & mode) ? 'r' : '-';
	perm[8] = (S_IWOTH & mode) ? 'w' : '-';
	perm[9] = (S_IXOTH & mode) ? 'x' : '-';
	perm[10] = '\0';
	if (S_ISUID & mode)
		perm[3] = perm[3] == '-' ? 'S' : 's';
	if (S_ISGID & mode)
		perm[6] = perm[6] == '-' ? 'S' : 's';
	if (S_ISVTX & mode)
		perm[9] = perm[9] == '-' ? 'T' : 't';
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