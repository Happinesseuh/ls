/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c for project my_ls
*/

#include "./includes/my_ls.h"
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
#include <pwd.h>

int number_file(char *filepath)
{
    int i = 0;
    DIR *opend = opendir(filepath);

    struct dirent *dir;
    dir = readdir(opend);
    for (i = 0; dir != NULL; i++) {
        dir = readdir(opend);
    }
    closedir(opend);
    return (i);
}

void ls_simple(struct dirent *dir, DIR *opend, char *filepath)
{
    for (int i = 0; i < number_file(filepath); i++) {
        dir = readdir(opend);
        if (dir->d_name[0] != '.')
            my_printf("%s", dir->d_name);
        if (dir->d_name[0] != '.' && (i + 1) != number_file(filepath))
            my_printf("  ");
    }
    my_printf("\n");
    closedir(opend);
}

void ls_mutiple(int i, char **av, DIR *opend)
{
    struct dirent *dir;

    while (av[i] != NULL) {
        opend = opendir(av[i]);
        if (opend == NULL) {
            write(2, "OPEN FAILED\n", 12);
            exit(84);
        }
        my_printf(":\n");
        ls_simple(dir, opend, av[i]);
        if (av[i + 1] != NULL)
            my_printf("\n");
    }
}

void my_ls(int ac, char **av, int i, int count)
{
    struct dirent *dir;
    DIR *opend = opendir(".");

    if (opend == NULL) {
        write(2, "OPEN FAILED\n", 12);
        exit(84);
    }

    if (ac == 1 || count == 0)
        ls_simple(dir, opend, ".");
    else if (count == 1) {
        opend = opendir(av[i]);
        if (opend == NULL) {
            write(2, "OPEN FAILED\n", 12);
            exit(84);
        }
        ls_simple(dir, opend, av[i]);
    } else
        if (count > 1)
            ls_mutiple(i, av, opend);
}

int main(int ac, char **av)
{
    DIR *opend = NULL;
    struct dirent *dir;
    struct stat sb;
    char *filepath = NULL;
    int count = 0;
    char **stk = NULL;
    int i = 0;

    if (ac > 1)
        for (i = 1; av[i][0] == '-' && av[i + 1] != NULL; i++);
        for (int j = i; av[j] != NULL; j++, count++);
    my_ls(ac, av, i, count);
    return (0);
}
