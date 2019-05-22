/*
** EPITECH PROJECT, 2019
** mlib
** File description:
** Many condition function
*/

static const int TRUE = 1;
static const int FALSE = 0;

int mis_num(char *str)
{
    if (!str)
        return (FALSE);
    for (int row = 0 ; str[row] ; row++) {
        if (str[row] >= '0' && str[row] <= '9');
        else
            return (FALSE);
    }
    return (TRUE);
}

int mis_alpha(char *str)
{
    if (!str)
        return (FALSE);
    for (int row = 0 ; str[row] ; row++) {
        if ((str[row] >= 'a' && str[row] <= 'z') ||
            (str[row] >= 'A' && str[row] <= 'Z'));
        else
            return (FALSE);
    }
    return (TRUE);
}

int mis_alphanum(char *str)
{
    if (!str)
        return (FALSE);
    for (int row = 0 ; str[row] ; row++) {
        if ((str[row] >= '0' && str[row] <= '9') ||
            (str[row] >= 'a' && str[row] <= 'z') ||
            (str[row] >= 'A' && str[row] <= 'Z'));
        else
            return (FALSE);
    }
    return (TRUE);
}
