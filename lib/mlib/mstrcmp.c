/*
** EPITECH PROJECT, 2019
** mlib
** File description:
** String comparator
*/

static const int TRUE = 1;
static const int FALSE = 0;

int mstrcmp(char *str1, char *str2)
{
    int i = 0;

    if (!str1 && !str2)
        return (FALSE);
    for ( ; str1[i] && str2[i] ; i++)
        if (str1[i] != str2[i])
            return (FALSE);
    return (TRUE);
}

int mstrsame(char *str1, char *str2)
{
    int i = 0;

    if (!str1 && !str2)
        return (FALSE);
    for ( ; str1[i] && str2[i] ; i++)
        if (str1[i] != str2[i])
            return (FALSE);
    if (str1[i] != str2[i])
        return (FALSE);
    return (TRUE);
}
