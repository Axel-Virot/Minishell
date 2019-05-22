/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** my_unsetenv function
*/

#include <stdlib.h>
#include "minishell.h"
#include "mlib.h"

//Optimisation == 0
//Should be in llist

int error_unsetenv(char **input)
{
    int ac = 0;

    for ( ; input[ac] ; ac++);
    if (ac == 0) {
        mputstr("unsetenv: Too few arguments.");
        return (ERROR);
    }
    return (SUCCESS);
}

int malloc_row_use(char ***new, char **envp, char **input)
{
    int size = 0;
    int nb_word = 0;

    for (int i = 1 ; input[i] ; i++)
        nb_word += is_word_in_arr_env(input[i], envp);
    size -= nb_word;
    for (int i = 0 ; envp[i] ; i++, size++);
    if (size < 0)
        return (ERROR);
    if ((*new = malloc(sizeof(char **) * (size + 1))) == NULL)
        return (ERROR);
    (*new)[size] = NULL;
    return (SUCCESS);
}

int malloc_col_use(char **new, char **envp, char **input, int *row)
{
    int col;
    int max = 0;

    for ( ; envp[max] ; max++);
    if (*row >= max)
        return (SUCCESS);
    if (!envp[++(*row)])
        return (SUCCESS);
    for (int i = 1 ; input[i] ; i++)
        if (is_word_in_str_env(input[i], envp[*row]) == TRUE) {
            malloc_col_use(new, envp, input, row);
            return (SUCCESS);
        }
    for (col = 0 ; envp[*row][col] ; col++);
    if ((*new = malloc(sizeof(char *) * (++col))) == NULL)
        return (ERROR);
    return (SUCCESS);
}

void fill_new_use(char **new, char **envp, char **input, int *row)
{
    int col;
    int max = 0;

    for ( ; envp[max] ; max++);
    if (*row >= max)
        return;
    if (!envp[++(*row)])
        return;
    for (int i = 1 ; input[i] ; i++)
        if (is_word_in_str_env(input[i], envp[*row]) == TRUE) {
            fill_new_use(new, envp, input, row);
            return;
        }
    for (col = 0 ; envp[*row][col] ; col++)
        (*new)[col] = envp[*row][col];
    (*new)[col] = '\0';
}

int my_unsetenv(char ***envp, char **input)
{
    char **new = NULL;
    int row;
    int row_envp = -1;

    if (error_unsetenv(input) == ERROR)
        return (SUCCESS);
    if (malloc_row_use(&new, *envp, input) == ERROR)
        return (ERROR);
    for (row = 0 ; (*envp)[row] ; row++)
        if (malloc_col_use(&new[row], *envp, input, &row_envp) == ERROR)
            return (ERROR);
    row_envp = -1;
    for (row = 0 ; (*envp)[row] ; row++)
        fill_new_use(&new[row], *envp, input, &row_envp);
    marr_free(*envp);
    *envp = new;
    return (SUCCESS);
}
