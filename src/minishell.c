/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** main functions
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "minishell.h"
#include "mlib.h"

static int builtin_command(builtin_t builtin, char ***env, char **input, int *s)
{
    if (mstrsame(input[0], builtin.command) == TRUE) {
        *s = builtin.function(env, input);
        if (mstrsame(input[0], "exit\0") == TRUE)
            return (TRUE);
        *s = STAY;
        return (TRUE);
    }
    return (FALSE);
}

static int interpreter(builtin_t *builtin, char ***env, char **input)
{
    int status = -1;

    if (!input)
        return (STAY);
    for (int i = 0 ; builtin[i].command ; i++)
        if ((builtin_command(builtin[i], env, input, &status)) == TRUE)
            return (status);
    execute(input, *env);
    return (STAY);
}

static int run_command(char *command, builtin_t *builtin, char ***env)
{
    char **arg = NULL;
    int status = -1;

    arg = marg(command);
    status = interpreter(builtin, env, arg);
    if (arg)
        marg_free(arg);
    return (status);
}

static int run_minishell(builtin_t *builtin, char ***env)
{
    char **command = NULL;
    char *line = NULL;
    int status;

    if (isatty(0) == 1)
        mputstr("$> ");
    if ((line = mgetline(stdin)) == NULL)
        return (SUCCESS);
    command = command_parser(line);
    for (int i = 0 ; command && command[i] ; i++)
        if ((status = run_command(command[i], builtin, env)) != STAY)
            break;
    if (command)
        marr_free(command);
    if (line)
        free(line);
    return (status);
}

int minishell(char **envp)
{
    builtin_t *builtin;
    char **env;
    int status;

    if ((env = marr_cln(envp)) == NULL)
        return (ERROR);
    if ((builtin = set_builtin()) == NULL)
        return (ERROR);
    while (1)
        if ((status = run_minishell(builtin, &env)) != STAY)
            return (status);
}
