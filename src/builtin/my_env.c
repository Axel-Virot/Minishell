/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** env function
*/

#include <unistd.h>
#include "minishell.h"
#include "mlib.h"

int my_env(char ***envp, char **input)
{
    if (!(*envp))
        return (ERROR);
    if (mrow(input) != 1)
        return (ERROR);
    for (int i = 0 ; (*envp)[i] ; i++) {
        mputstr((*envp)[i]);
        mputchar('\n');
    }
    return (SUCCESS);
}
