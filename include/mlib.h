/*
** EPITECH PROJECT, 2019
** mlib
** File description:
** mlib header, create by Axel Virot
*/

#ifndef MLIB_H_
#define MLIB_H_

//marg.c
char **marg(char *str);
void marg_free(char **arg);

//marray.c
int mrow(char **array);
void marr_free(char **array);

//marr_cp.c
int **marr_cp(char **arr, char **dest);
char **marr_cln(char **arr);

//mcond.c
int mis_num(char *str);
int mis_alpha(char *str);
int mis_alphanum(char *str);

//mgetline.c
char *mgetline();

//mgetnbr.c
int mgetnbr(char *str);

//mputnbr.c
int mputnbr(int nb);

//mputstr.c
int mputchar(char c);
int mputstr(char *str);
int mputerr(char *str);

//mstrcat.c
char *mstrcat(char *str1, char *str2);

//mstrcmp.c
int mstrcmp(char *str1, char *str2);
int mstrsame(char *str1, char *str2);

//mstr_cp.c
int mstr_cp(char *str, char *dest);
char *mstr_cln(char *str);

#endif /* MLIB_H_ */
