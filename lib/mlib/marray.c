/*
** EPITECH PROJECT, 2019
** mlib
** File description:
** Some array gestion function
*/

#include <stdlib.h>

int mrow(char **array)
{
    int row = 0;

    if (!array)
        return (-1);
    for ( ; array[row] ; row++);
    return (row);
}

void marr_free(char **array)
{
    if (!array)
        return ;
    for (int i = 0 ; array[i] ; i++)
        free(array[i]);
    free(array);
}
