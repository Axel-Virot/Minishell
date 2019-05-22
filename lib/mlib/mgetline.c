/*
** EPITECH PROJECT, 2019
** mlib
** File description:
** Get the next line
*/

#include <stdio.h>

static void cut_line_return(char **line)
{
    int row = 0;

    if (!(*line))
        return;
    for ( ; (*line)[row] && (*line)[row] != '\n' ; row++);
    (*line)[row] = '\0';
}

char *mgetline(FILE *fp)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (fp == NULL)
        return (NULL);
    if (getline(&line, &len, fp) < 0)
        return (NULL);
    cut_line_return(&line);
    return (line);
}
