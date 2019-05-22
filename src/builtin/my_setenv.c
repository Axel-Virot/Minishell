/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** setenv function
*/

#include <stdlib.h>
#include "minishell.h"
#include "mlib.h"

//Optimisation and property == NULL
//Should be rewrite with llist
//Same for unsetenv.c

static int error_setenv(char **input, char **envp, int *ac)
{
    if (!input)
        return (ERROR);
    for ( ; input[*ac] ; (*ac)++);
    if (*ac == 1) {
        my_env(&envp, marg("env\0"));
        return (ERROR);
    }
    if (*ac > 3) {
        mputstr("setenv: Too many arguments.\n");
        return (ERROR);
    }
    if (mis_alphanum(input[1]) == FALSE) {
        mputstr("setenv: Variable name must contain");
        mputstr(" alphanumeric characters.\n");
        return (ERROR);
    }
    return (SUCCESS);
}

static int malloc_col_se(char **new, char **envp, char *str)
{
    int row = 0;
    int col;

    for ( ; envp[row] ; row++) {
        for (col = 0 ; envp[row][col] ; col++);
        if ((new[row] = malloc(sizeof(char *) * (++col))) == NULL)
            return (ERROR);
    }
    for (col = 0 ; str[col] ; col++);
    if ((new[row] = malloc(sizeof(char *) * (col + 2))) == NULL)
        return (ERROR);
    return (SUCCESS);
}

static void fill_new_se(char **new, char **envp, char *str)
{
    int row = 0;
    int col;

    for ( ; envp[row] ; row++) {
        for (col = 0 ; envp[row][col] ; col++)
            new[row][col] = envp[row][col];
        new[row][col] = '\0';
    }
    for (col = 0 ; str[col] ; col++)
        new[row][col] = str[col];
    new[row][col++] = '=';
    new[row][col] = '\0';
}

static int str_add_arg_se(char **arr, char *str_to_find, char *str)
{
    char *new = NULL;
    int pos = 0;
    int ptr = 0;
    int size = 0;

    pos = where_word_in_arr_env(str_to_find, arr);
    for (int i = 0 ; arr[pos][i + 1] && arr[pos][i] != '=' ; i++, size++);
    if (str)
        for (int i = 0 ; str[i] ; i++, size++);
    if ((new = malloc(sizeof(char *) * (size + 1))) == NULL)
        return (ERROR);
    for (int i = 0 ; arr[pos][i] != '=' ; i++)
        new[ptr++] = arr[pos][i];
    new[ptr++] = '=';
    if (str)
        for (int i = 0 ; str[i] ; i++)
            new[ptr++] = str[i];
    new[ptr++] = '\0';
    free(arr[pos]);
    arr[pos] = new;
    return (SUCCESS);
}

int my_setenv(char ***envp, char **input)
{
    char **new = NULL;
    char *arg = NULL;
    int row = 0;
    int ac = 0;

    if (error_setenv(input, *envp, &ac) == ERROR)
        return (SUCCESS);
    if (is_word_in_arr_env(input[1], *envp) == FALSE) {
        for ( ; (*envp)[row] ; row++);
        if ((new = malloc(sizeof(char **) * (row + 2))) == NULL)
            return (ERROR);
        new[row + 1] = NULL;
        if (malloc_col_se(new, *envp, input[1]) == ERROR)
            return (ERROR);
        fill_new_se(new, *envp, input[1]);
        marr_free(*envp);
        *envp = new;
    }
    arg = input[2] ? input[2] : NULL;
    str_add_arg_se(*envp, input[1], arg);
    return (SUCCESS);
}
