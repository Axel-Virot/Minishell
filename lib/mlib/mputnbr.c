/*
** EPITECH PROJECT, 2018
** mlib
** File description:
** Put int
*/

#include <unistd.h>

static const int SUCCESS = 0;
static const int ERROR = 84;

static int mputchar(char c)
{
    if (write(1, &c, 1) == -1)
        return (ERROR);
    return (SUCCESS);
}

static int negatif(int nb, int size)
{
    if (nb < 0 && nb != -2147483648) {
        nb = -1 * nb;
        size = -1 * size;
        if (mputchar('-') == ERROR)
            return (-1);
    }
    return (nb);
}

static int nb_null(int nb)
{
    if (nb == 0)
        if (mputchar('0') == ERROR)
            return (ERROR);
    return (SUCCESS);
}

static int put_nb(int nb, int counter)
{
    int rest = 0;

    while (counter > 0) {
        rest = nb / counter + 48;
        if (mputchar(rest) == ERROR)
            return (ERROR);
        nb = nb % counter;
        counter = counter / 10;
    }
    return (SUCCESS);
}

int mputnbr(int nb)
{
    int size = 0;
    long  counter = 1;

    if (nb == -2147483648) {
        if (write (1, "-2147483648", 11) == -1)
            return (ERROR);
        return (SUCCESS);
    }
    if ((nb = negatif(nb, size)) == -1)
        return (ERROR);
    size = nb;
    if (nb_null(nb) == ERROR)
        return (ERROR);
    while (size >= 1) {
        counter = counter * 10;
        size = size / 10;
    }
    counter = counter / 10;
    if (put_nb(nb, counter) == ERROR)
        return (ERROR);
    return (SUCCESS);
}
