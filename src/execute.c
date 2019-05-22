/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** execute function
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "minishell.h"
#include "mlib.h"

static char *found_path(char *path, char **envp)
{
    char **dif_path = NULL;
    int row = 0;

    if (access(path, X_OK) == 0)
        return (path);
    for ( ; envp[row] ; row++)
        if (is_word_in_str_env("PATH", envp[row]) == TRUE)
            break;
    if (!envp[row])
        return (NULL);
    dif_path = str_to_array_exec(envp[row]);
    for (row = 0 ; dif_path[row] ; row++) {
        if ((dif_path[row] = mstrcat(dif_path[row], path)) == NULL)
            return (NULL);
        if (access(dif_path[row], X_OK) == 0)
            return (dif_path[row]);
    }
    return (NULL);
}

static void child_verif(int status)
{
    if (WIFSIGNALED(status)) {
        if (status == 139)
            mputstr("Segmentation fault");
        if (status == 136)
            mputstr("Floating exception");
        mputchar('\n');
    }
}

void execute(char **input, char **envp)
{
    char *path = NULL;
    int status = 0;
    pid_t pid;

    if ((path = found_path(input[0], envp)) == NULL) {
        mputstr(input[0]);
        mputstr(": Command not found.\n");
        return;
    }
    pid = fork();
    if (pid == -1)
        return;
    if (pid == 0)
        if (execve(path, input, envp) == -1) {
            mputstr(path);
            mputstr(": Permission denied.\n");
            exit(0);
            return;
        }
    pid = waitpid(pid, &status, 0);
    child_verif(status);
}
