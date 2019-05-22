/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** header
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

static const int ERROR = 84;
static const int SUCCESS = 0;
static const int TRUE = 1;
static const int FALSE = 0;

//minishell and builtin const, prompt loop
static const int STAY = -1;
static const int STOP = -2;

//Builtin parser struct
typedef struct builtin_s {
    char *command;
    int (*function)(char ***, char **);
} builtin_t;

//Main function
int minishell(char **envp);
void execute(char **imput, char **envp);

//Builtin
builtin_t *set_builtin(void);
int my_exit(char ***env, char **input);
// ---> cd
int my_cd(char ***env, char **input);
int my_cd_no_arg(char ***envp);
int set_pwd(char ***envp);
int set_old_pwd(char ***envp);
int my_cd_malus(char ***envp);
// cd <---
int my_env(char ***envp, char **input);
int my_setenv(char ***envp, char **imput);
int my_unsetenv(char ***envp, char **imput);

//Tool
int is_word_in_str_env(char *word, char *str);
int where_word_in_arr_env(char *word, char **arr);
int is_word_in_arr(char *word, char **arr);
int is_word_in_arr_env(char *word, char **arr);
int is_word_in_str(char *word, char *str);
char **str_to_array_exec(char *str);
char **command_parser(char *str);

#endif /* MINISHELL_H_ */
