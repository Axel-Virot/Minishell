/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** my_exit function
*/

#include <unistd.h>
#include "minishell.h"
#include "mlib.h"

int my_exit(char ***env, char **input)
{
    int ac = mrow(input);

    (void)env;
    if (ac == 1) {
        mputstr("exit\n");
        return (SUCCESS);
    }
    if (ac > 2) {
        mputstr("exit: Expression Syntax.\n");
        return (STAY);
    }
    for (int i = 0 ; input[1][i] ; i++)
        if (input[1][i] < '0' || input[1][i] > '9') {
            mputstr("exit: Expression Syntax.\n");
            return (STAY);
        }
    mputstr("exit\n");
    return (mgetnbr(input[1]));
}
