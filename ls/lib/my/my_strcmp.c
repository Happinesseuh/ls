/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** compare two strings
*/

#include <unistd.h>
#include <stdio.h>

char *my_strlowcase(char *str);

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int i;
    char *dest = NULL;

    dest = malloc(sizeof(char) * my_strlen(src));
    for (i = 0; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

int my_strcmp(char const *s1, char const *s2)
{
    char *str1 = my_strlowcase(my_strdup(s1));
    char *str2 = my_strlowcase(my_strdup(s2));
    int i = 0;

    for (; (str1[i] != '\0' && str2[i] != '\0') && str1[i] == str2[i]; i++);
    return (str1[i] - str2[i]);
}