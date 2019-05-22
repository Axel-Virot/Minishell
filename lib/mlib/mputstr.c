/*
** EPITECH PROJECT, 2019
** mlib
** File description:
** Put char* and char
*/

#include <unistd.h>

static const int SUCCESS = 0;
static const int ERROR = 0;

int mputchar(char c)
{
    if (write(1, &c, 1) == -1)
        return (ERROR);
    return (SUCCESS);
}

int mputstr(char *str)
{
    int len = 0;

    if (!str)
        return (ERROR);
    for ( ; str[len] ; len++);
    if (write(1, str, len) == -1)
        return (ERROR);
    return (SUCCESS);
}

int mputerr(char *str)
{
    int len = 0;

    for ( ; str[len] ; len++);
    if (write(2, str, len) == -1)
        return (ERROR);
    return (SUCCESS);
}
