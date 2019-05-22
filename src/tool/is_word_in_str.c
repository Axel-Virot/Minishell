/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** is_word_in_str function
*/

#include "minishell.h"

int is_word_in_str_env(char *word, char *str)
{
    int ii = 0;

    for (int i = 0 ; str[i + 1] ; i++) {
        if (str[i] == word[ii])
            ii++;
        else
            return (FALSE);
        if (str[i + 1] == '=' && !word[i + 1])
            return (TRUE);
    }
    return (FALSE);
}

int is_word_in_str(char *word, char *str)
{
    int ii = 0;

    for (int i = 0 ; str[i] ; i++) {
        if (str[i] == word[ii])
            ii++;
        else
            ii = 0;
        if (!word[ii])
            return (TRUE);
    }
    return (FALSE);
}

int is_word_in_arr_env(char *word, char **arr)
{
    for (int i = 0 ; arr[i] ; i++) {
        if (is_word_in_str_env(word, arr[i]) == TRUE)
            return (TRUE);
    }
    return (FALSE);
}

int is_word_in_arr(char *word, char **arr)
{
    for (int i = 0 ; arr[i] ; i++) {
        if (is_word_in_str(word, arr[i]) == TRUE)
            return (TRUE);
    }
    return (FALSE);
}

int where_word_in_arr_env(char *word, char **arr)
{
    int pos = 0;

    for ( ; arr[pos] ; pos++) {
        if (is_word_in_str_env(word, arr[pos]) == TRUE)
            return (pos);
    }
    return (--pos);
}
