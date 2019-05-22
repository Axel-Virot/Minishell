/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** Chdir OLDPWD, and set PWD / OLDPWD
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "mlib.h"

static char *str_path_cd(char **envp)
{
    char *str = NULL;
    int row = 0;
    int col = 0;

    for ( ; envp[row] ; row++)
        if (is_word_in_str_env("OLDPWD\0", envp[row]) == TRUE)
            break;
    if (!envp[row])
        return (NULL);
    for (int i = 0 ; envp[row][i] ; i++, col++);
    str = malloc(sizeof(char *) * (col));
    col = 0;
    for (int i = 7 ; envp[row][i] ; i++)
        str[col++] = envp[row][i];
    str[col] = '\0';
    return (str);
}

int my_cd_malus(char ***envp)
{
    char *path = NULL;
    char buf[256];

    if ((path = str_path_cd(*envp)) == NULL)
        return (ERROR);
    if (set_old_pwd(envp) == ERROR)
        return (ERROR);
    if (chdir(path) == -1)
        return (ERROR);
    if (getcwd(buf, 256) == NULL)
        return (ERROR);
    mputstr(buf);
    mputchar('\n');
    if (set_pwd(envp) == ERROR)
        return (ERROR);
    return (SUCCESS);
}
