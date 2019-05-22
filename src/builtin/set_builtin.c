/*
** EPITECH PROJECT, 2019
** Shell
** File description:
** Set the builtin command
*/

#include <stdlib.h>
#include "minishell.h"

builtin_t *set_builtin(void)
{
    builtin_t *builtin;

    builtin = malloc(sizeof(builtin_t) * 6);
    builtin[0].command = "exit\0";
    builtin[0].function = my_exit;
    builtin[1].command = "cd\0";
    builtin[1].function = my_cd;
    builtin[2].command = "env\0";
    builtin[2].function = my_env;
    builtin[3].command = "setenv\0";
    builtin[3].function = my_setenv;
    builtin[4].command = "unsetenv\0";
    builtin[4].function = my_unsetenv;
    builtin[5].command = NULL;
    builtin[5].function = NULL;
    return (builtin);
}
