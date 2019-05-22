/*
** EPITECH PROJECT, 2019
** mlib.h
** File description:
** str_cat function
*/

#include <stdlib.h>

char *mstrcat(char *str1, char *str2)
{
    char *new = NULL;
    int size = 0;
    int pos = 0;

    if (!str1 || !str2)
        return (NULL);
    for (int i = 0 ; str1[i] ; i++, size++);
    for (int i = 0 ; str2[i] ; i++, size++);
    if ((new = malloc(sizeof(char *) * (++size))) == NULL)
        return (NULL);
    for (int i = 0 ; str1[i] ; i++)
        new[pos++] = str1[i];
    for (int i = 0 ; str2[i] ; i++)
        new[pos++] = str2[i];
    new[pos] = '\0';
    return (new);
}
