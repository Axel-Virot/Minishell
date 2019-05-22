/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** main
*/

#include "minishell.h"

int main(int ac, char **av, char **envp)
{
    if (ac != 1)
        return (ERROR);
    (void)av;
    return (minishell(envp));
}
