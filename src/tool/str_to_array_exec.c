/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** str to word special execute
*/

#include <stdlib.h>
#include "minishell.h"

#include "mlib.h"

static int calc_nb_arg(char *str)
{
    int row = 0;
    int nb_arg = 0;

    for ( ; str[row] ; row++)
        if ((str[row] != ':') &&
            (!str[row + 1] || str[row + 1] == ':' || str[row + 1] == '\n'))
            nb_arg++;
    return (nb_arg);
}

static int calc_nb_char(char *str, int row)
{
    int nb_char = 0;

    for ( ; str[row] && str[row] == ':' ; row++);
    for ( ; str[row] ; row++) {
        nb_char++;
        if ((str[row] != ':') &&
            (!str[row + 1] || str[row + 1] == ':' || str[row + 1] == '\n'))
            break;
    }
    return (nb_char + 2);
}

static char *fill_arg(char *str, int turn)
{
    int row = 0;
    int nb_char = 0;
    char *arg = NULL;

    for (int nb_arg = 0 ; str[row] && nb_arg < turn ; row++)
        if (str[row] != ':' && str[row + 1] == ':')
            nb_arg++;
    nb_char = calc_nb_char(str, row);
    if (!(arg = malloc(sizeof(char *) * nb_char)))
        return (NULL);
    for ( ; str[row] && str[row] == ':' ; row++);
    for (int i = 0 ; str[row] ; row++, i++) {
        arg[i] = str[row];
        if ((str[row] != ':') &&
            (!str[row + 1] || str[row + 1] == ':' || str[row + 1] == '\n'))
            break;
    }
    arg[--nb_char] = '\0';
    arg[--nb_char] = '/';
    return (arg);
}

static void replace_str(char *str)
{
    str[0] = ':';
    str[1] = ':';
    str[2] = ':';
    str[3] = ':';
    str[4] = ':';
}

char **str_to_array_exec(char *str)
{
    int nb_arg = 0;
    char **array = NULL;
    char *cpy = NULL;

    if (!str)
        return (NULL);
    if ((cpy = mstr_cln(str)) == NULL)
        return (NULL);
    replace_str(cpy);
    nb_arg = calc_nb_arg(cpy);
    if (!(array = malloc(sizeof(char *) * (nb_arg + 1))))
        return (NULL);
    for (int row = 0 ; row < nb_arg ; row++)
        if (!(array[row] = fill_arg(cpy, row)))
            return (NULL);
    array[nb_arg] = NULL;
    free(cpy);
    return (array);
}
