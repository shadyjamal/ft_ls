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

typedef struct s_content
{
    char                *filename;
    char                *permissions;
    char                *timelastmodif;
    int                 size;
    char                *user;
    char                *group;
    struct s_content    *next;
}               t_content;

typedef struct s_lstdir
{
    DIR                 *op;
    struct dirent       *entry;
    char                *dirname;
    char                *prms;
    char                *timelstmdf;
    int                 size;
    char                *user;
    char                *group;
    struct s_content    *files;
    struct s_dir        *next;
}               t_lstdir;
#endif