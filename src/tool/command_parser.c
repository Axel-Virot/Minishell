/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** parse the cinput into multiple command
*/

#include <stdlib.h>

static int calc_nb_arg(char *str)
{
    int row = 0;
    int nb_arg = 0;

    for ( ; str[row] ; row++)
        if (str[row] != ';' &&
            (!str[row + 1] || str[row + 1] == ';' || str[row + 1] == '\n'))
            nb_arg++;
    return (nb_arg);
}

static int calc_nb_char(char *str, int row)
{
    int nb_char = 0;

    for ( ; str[row] && str[row] == ';' ; row++);
    for ( ; str[row] ; row++) {
        nb_char++;
        if (str[row] != ';' &&
            (!str[row + 1] || str[row + 1] == ';' || str[row + 1] == '\n'))
            break;
    }
    return (++nb_char);
}

static char *fill_arg(char *str, int turn)
{
    int row = 0;
    int nb_char = 0;
    char *arg = NULL;

    for (int nb_arg = 0 ; str[row] && nb_arg < turn ; row++)
        if (str[row] != ';' && str[row + 1] == ';')
            nb_arg++;
    nb_char = calc_nb_char(str, row);
    if (!(arg = malloc(sizeof(char *) * nb_char)))
        return (NULL);
    for ( ; str[row] && str[row] == ';' ; row++);
    for (int i = 0 ; str[row] ; row++, i++) {
        arg[i] = str[row];
        if (str[row] != ';' &&
            (!str[row + 1] || str[row + 1] == ';' || str[row + 1] == '\n'))
            break;
    }
    arg[--nb_char] = '\0';
    return (arg);
}

char **command_parser(char *str)
{
    int nb_arg = 0;
    char **array;

    if (!str)
        return (NULL);
    nb_arg = calc_nb_arg(str);
    if (!(array = malloc(sizeof(char *) * (nb_arg + 1))))
        return (NULL);
    for (int row = 0 ; row < nb_arg ; row++)
        if (!(array[row] = fill_arg(str, row)))
            return (NULL);
    array[nb_arg] = NULL;
    return (array);
}
