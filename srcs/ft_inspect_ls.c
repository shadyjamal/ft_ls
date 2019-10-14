/*
int stat(const char *restrict path, struct stat *restrict buf); 
    function obtains information about the file pointed to by path.

int lstat(const char *restrict path, struct stat *restrict buf);
        symbolik link difference*/



// Nom: un_fichier_de_ouf
// Type: Fichier
// Modes: rwxr-xr-x
// Nombre de liens: 1
// Proprietaire: zaz
// Groupe: staff
// Taille: 2142 octets
// Date de derniere modification: Sep 17 23:42
#include <sys/types.h>
#include <sys/stat.h>
#include <uuid/uuid.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *ft_typeoffile(mode_t st_mode)
{
    if ((S_IFDIR & st_mode))
        return ("Directory");
    if ((S_IFREG & st_mode))
        return ("Fichier");
    if ((S_IFLNK & st_mode))
        return ("Link");
    return (NULL);
}

void ft_getmode(mode_t st_mode, char **mod)
{
    (*mod)[0] = (S_IRUSR & st_mode ? 'r' : '-');
    (*mod)[1] = (S_IWUSR & st_mode ? 'w' : '-');
    (*mod)[2] = (S_IXUSR & st_mode ? 'x' : '-');
    (*mod)[3] = (S_IRGRP & st_mode ? 'r' : '-');
    (*mod)[4] = (S_IWGRP & st_mode ? 'w' : '-');
    (*mod)[5] = (S_IXGRP & st_mode ? 'x' : '-');
    (*mod)[6] = (S_IROTH & st_mode ? 'r' : '-');
    (*mod)[7] = (S_IWOTH & st_mode ? 'w' : '-');
    (*mod)[8] = (S_IXOTH & st_mode ? 'x' : '-');
    (*mod)[9] = '\0';
}
int main (int ac, char **av)
{
    struct stat buf;
    char        *mode;
    
    mode = (char*)malloc(10);
    ac = 0;
    if (stat(av[1], &buf) == 0)
    {
        ft_getmode(buf.st_mode, &mode);
        printf("Nom: %s\n", av[1]);
        printf("Type: %s\n", ft_typeoffile(buf.st_mode));
        printf("Modes: %s\n", mode);
        printf("Nombre de liens: %d\n", buf.st_nlink);
        printf("Proprietaire: %s\n",getpwuid(buf.st_uid)->pw_name);
        printf("Groupe: %s\n",getgrgid(buf.st_gid)->gr_name);
        printf("Taille: %lld octets\n",buf.st_size);
        printf("Date de derniere modification: %ld", buf.st_mtimespec.tv_sec);
    }
    return (0);
}