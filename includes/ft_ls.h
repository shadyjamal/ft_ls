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
#include "../libft/libft.h"

#define LS_a 1
#define LS_l 2
#define LS_r 4
#define LS_upr 8
#define LS_t 16

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
	struct s_file	*next;
}					t_file;
#endif

void    parse_arg(int ac, char **av, int *flag, t_list **begin);

int		ft_sort_tab(char **tab, int size);

void   ls_main(t_list *begin, int *flag);

void    getdata(t_file **files, char *name, char *path);
t_file    *storedata(t_list *file, int *flag);

//debug

void printtab(char **str, int size);
void printlst(t_list *begin);
void printlstfile(t_file *begin);

// display
void    ft_display(t_file *list, int *flag);
void    print_error(char *content);
void    dir_name(char *dirname);
// free
void	freelst(t_file **begin);