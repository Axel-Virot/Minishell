/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** Set the env OLDPWD and PWD
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "mlib.h"

int set_pwd(char ***envp)
{
    char **arg = NULL;
    char *path = NULL;
    char *base = NULL;
    char buf[256];

    if ((base = mstr_cln("setenv PWD \0")) == NULL)
        return (ERROR);
    if (getcwd(buf, 256) == NULL)
        return (ERROR);
    if ((path = mstrcat(base, buf)) == NULL)
        return (ERROR);
    if ((arg = marg(path)) == NULL)
        return (ERROR);
    if (my_setenv(envp, arg) == ERROR)
        return (ERROR);
    free(path);
    free(base);
    marg_free(arg);
    return (SUCCESS);
}

int set_old_pwd(char ***envp)
{
    char **arg = NULL;
    char *path = NULL;
    char *base = NULL;
    char buf[256];

    if ((base = mstr_cln("setenv OLDPWD \0")) == NULL)
        return (ERROR);
    if (getcwd(buf, 256) == NULL)
        return (ERROR);
    if ((path = mstrcat(base, buf)) == NULL)
        return (ERROR);
    if ((arg = marg(path)) == NULL)
        return (ERROR);
    if (my_setenv(envp, arg) == ERROR)
        return (ERROR);
    free(path);
    free(base);
    marg_free(arg);
    return (SUCCESS);
}
