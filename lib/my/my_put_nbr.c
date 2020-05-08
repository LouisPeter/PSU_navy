/*
** EPITECH PROJECT, 2018
** my_lib
** File description:
** my_putnbr
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

int my_put_nbr(int nb)
{
    int a;
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            a = nb % 10;
            nb = (nb - a) / 10;
            my_put_nbr(nb);
            my_putchar(a + 48);
        } else {
            my_putchar(nb + 48);
        }
    }
    return (0);
}
