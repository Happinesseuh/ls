/*
** EPITECH PROJECT, 2020
** my_ls.h
** File description:
** my_ls
*/

#include <dirent.h>
#ifndef _MY_LS_
#define _MY_LS_

typedef struct flag_s {
    int l;
    int R;
    int d;
    int a;
}flag_t;

void sort(char **str);
void flag_up_r(struct dirent *dir, char *filepath);
char *mode_permission(int mode, char *str);
void flag_l(struct dirent *dir, char *filepath);
void flag_d(int i, char **av);

#endif /* !_MY_LS_ */
