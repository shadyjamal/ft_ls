#ifndef FT_LS_H
#define FT_LS_H

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <uuid/uuid.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/errno.h>
#include <time.h>
#include "../libft/libft.h"

# define C_RESET         "\033[0m"
# define C_BLACK        "\033[30m"
# define C_RED          "\033[31m"
# define C_PURPLE        "\033[95m"
# define C_BROWN        "\033[33m"
# define C_BLUE         "\033[34m"
# define C_GREEN      "\033[32m"
# define C_CYAN         "\033[1;36m"
# define C_GRAY         "\033[37m"
# define B_YELLOW		"\033[30;43m"
# define B_YELLOWB		"\033[34;103m"
# define B_CYAN			"\033[34;46m"

# define LS_a 1
# define LS_l 2
# define LS_r 4
# define LS_upr 8
# define LS_t 16
# define LS_u 32
# define LS_upu 64
# define LS_upg 128

# define BUFSIZE 1000	

enum {ERRNO, USAGE, MALERROR};

typedef struct		s_size
{
	int				susrname;
	int				sgrname;
	int				snlink;
	int				ssize;
	int				smaj;
	int				smin;
	int				stotal;
}					t_size;

typedef struct		s_file
{
	time_t			date;
	mode_t			st_mode;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	off_t			st_size;
	quad_t			st_blocks;
	dev_t			st_dev;
	time_t			time_s;
	long			time_ns;
	char			*name;
	char			*path;
	struct s_file	*next;
}					t_file;


#endif

void    parse_arg(int ac, char **av, int *flag, t_list **begin);
int		ft_sort_tab(char **tab, int size);
void	ls_main(t_list *begin, int *flag, int multidir);
void	getdata(t_file **files, char *name, char *path, int *flag);

// display
void    display_lnk(t_file *lst, char buf[NAME_MAX]);
void    ft_display(t_file *list, int *flag, _Bool fileordir);
void    ft_simple_display(t_file *list, int *flag);
void    print_error(char *content, int error);
void    dir_name(char *dirname, _Bool first);
void	ft_print_int(int nb, int size);
void	ft_print_str(char *str, int size);
void	ft_print_majmin(t_file *file, t_size size);
void	print_date(time_t date);
void	ft_getperms(char perm[11], int mode);
void	ft_color(char prm[11]);
void	do_lsdir(t_file *files, int *flag);

// free
void	freelst(t_file **begin);
void	freecontent(void *content, size_t contentsize);
void	freenode(t_file *node);

//sort
void 	ft_mergesortlst(t_file **headRef, int (*cmp)(t_file*, t_file*));
void	ft_sortlst(t_file **head, int *flag);

// size
t_size	ft_getsize(t_file *list, int *blocks);
