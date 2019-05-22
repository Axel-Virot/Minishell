/*
** EPITECH PROJECT, 2019
** mlib
** File description:
** Copy a char ** | cp -> no malloc, cln -> malloc
*/

#include <stdlib.h>

static const int SUCCESS = 0;
static const int ERROR = 84;

static int mrow(char **array)
{
    int row = 0;

    if (!array)
        return (-1);
    for ( ; array[row] ; row++);
    return (row);
}

static int malloc_col_ac(char **cpy, char **arr)
{
    int row = 0;
    int col;

    for ( ; arr[row] ; row++) {
        for (col = 0 ; arr[row][col] ; col++);
        if ((cpy[row] = malloc(sizeof(char *) * (++col))) == NULL)
            return (ERROR);
    }
    return (SUCCESS);
}

int marr_cp(char **arr, char **dest)
{
    int row = 0;
    int col = 0;

    if (!arr)
        return (ERROR);
    if (!dest)
        return (ERROR);
    for ( ; arr[row] ; row++) {
        for (col = 0 ; arr[row][col] ; col++)
            dest[row][col] = arr[row][col];
        dest[row][col] = '\0';
    }
    return (SUCCESS);
}

char **marr_cln(char **arr)
{
    char **cpy = NULL;
    int row = mrow(arr);
    int col = 0;

    if ((cpy = malloc(sizeof(char **) * (row + 1))) == NULL)
        return (NULL);
    cpy[row] = NULL;
    if (malloc_col_ac(cpy, arr) == ERROR)
        return (NULL);
    marr_cp(arr, cpy);
    return (cpy);
}
