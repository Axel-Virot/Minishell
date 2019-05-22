/*
** EPITECH PROJECT, 2019
** mlib
** File description:
** Copy or clone a string
*/

#include <stdlib.h>

static const int SUCCESS = 0;
static const int ERROR = 84;

int mstr_cp(char *str, char *dest)
{
    int row = 0;

    if (!str || !dest)
        return (ERROR);
    for ( ; str[row] ; row++)
        dest[row] = str[row];
    dest[row] = '\0';
    return (SUCCESS);
}

char *mstr_cln(char *str)
{
    char *cpy = NULL;
    int row = 0;

    if (!str)
        return (NULL);
    for ( ; str[row] ; row++);
    if ((cpy = malloc(sizeof(char *) * ++row)) == NULL)
        return (NULL);
    mstr_cp(str, cpy);
    return (cpy);
}
