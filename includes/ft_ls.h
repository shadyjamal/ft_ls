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

# define C_NONE         "\033[0m"
# define C_BOLD         "\033[1m"
# define C_BLACK        "\033[30m"
# define C_RED          "\033[31m"
# define C_GREEN        "\033[32m"
# define C_BROWN        "\033[33m"
# define C_BLUE         "\033[34m"
# define C_MAGENTA      "\033[35m"
# define C_CYAN         "\033[36m"
# define C_GRAY         "\033[37m"

# define LS_a 1
# define LS_l 2
# define LS_r 4
# define LS_upr 8
# define LS_t 16
# define LS_u 32
# define LS_upu 64

# define BUFFSIZE 1000

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
	char			*name;
	char			*path;
	time_t			date;
	mode_t			st_mode;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	off_t			st_size;
	quad_t			st_blocks;
	dev_t			st_rdev;
	time_t			time_s;
	long			time_ns;
	struct s_file	*next;
}					t_file;


#endif

void    parse_arg(int ac, char **av, int *flag, t_list **begin);

int		ft_sort_tab(char **tab, int size);

void	ls_main(t_list *begin, int *flag, int multidir);

void	getdata(t_file **files, char *name, char *path, int *flag);
t_file	*storedata(t_list *file, int *flag);

//debug

void	printtab(char **str, int size);
void	printlst(t_list *begin);
void	printlstfile(t_file *begin);
void	printsize(t_size *size);

// display
void    ft_display(t_file *list, int *flag, _Bool fileordir);
void    print_error(char *content, int error);
void    dir_name(char *dirname, _Bool first);
void	ft_printperms(char perm[11], int mode);
void	ft_print_int(int nb, int size);
void	ft_print_str(char *str, int size);
void	ft_print_majmin(t_file *file, t_size size);
void	print_date(time_t date);

// free
void	freelst(t_file **begin);

//sort
void 	ft_mergesortlst(t_file **headRef, int (*cmp)(t_file*, t_file*));
void	ft_sortlst(t_file **head, int *flag);

// size
t_size	ft_getsize(t_file *list, int *blocks);
