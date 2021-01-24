/*
** EPITECH PROJECT, 2020
** flag_ls.c
** File description:
** flag us for ls
*/

#include "./includes/my.h"
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/sysmacros.h>
#include <grp.h>

char *mode_permission(int mode, char *str)
{
    str[0] = '-';
    if (S_ISDIR(mode)) str[0] = 'd';
    if (S_ISCHR(mode)) str[0] = 'c';
    if (S_ISBLK(mode)) str[0] = 'b';
    (mode & S_IRUSR) ? (str[1] = 'r') : (str[1] = '-');
    (mode & S_IWUSR) ? (str[2] = 'w') : (str[2] = '-');
    (mode & S_IXUSR) ? (str[3] = 'x') : (str[3] = '-');
    (mode & S_IRGRP) ? (str[4] = 'r') : (str[4] = '-');
    (mode & S_IWGRP) ? (str[5] = 'w') : (str[5] = '-');
    (mode & S_IXGRP) ? (str[6] = 'x') : (str[6] = '-');
    (mode & S_IROTH) ? (str[7] = 'r') : (str[7] = '-');
    (mode & S_IWOTH) ? (str[8] = 'w') : (str[8] = '-');
    (mode & S_IXOTH) ? (str[9] = 'x') : (str[9] = '-');
    str[10] = '.';
    str[11] = ' ';
    str[12] = '\0';
    return (str);
}

void flag_d(int i, char **av)
{
    if (av[2] == NULL) {
        my_printf(".\n");
        return;
    }
    for (; av[i] != NULL; i++) {
        my_printf("%s", (av[i]));
        if (av[i + 1] != NULL)
            my_printf("  ");
        else
            my_printf("\n");
    }
}