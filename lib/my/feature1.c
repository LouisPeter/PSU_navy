/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** feature1
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "../../include/my.h"

void decimal_binary(unsigned int nb)
{
    unsigned int r;
    char *bin = malloc(sizeof(char) + 4294967296);

    if (nb == 0){
        my_putchar(0 + '0');
        return;
    }
    if (nb < 0)
        return;
    for (unsigned int i = 0; nb != 0; i++) {
        r = (nb % 2);
        nb = nb / 2;
        bin[i] = (r + 48);
    }
    my_revstr(bin);
    my_putstr(bin);
    free(bin);
}

void decimal_octal(unsigned int nb)
{
    unsigned int r;
    char *bin = malloc(sizeof(int) + 4294967296);
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    for (int i = 0; nb != 0; i++) {
        r = (nb % 8);
        nb = nb / 8;
        bin[i] = (r + 48);
    }
    my_revstr(bin);
    my_putstr(bin);
    free(bin);
}

void unsign_int(unsigned int nb)
{
    unsigned int a;
    if (nb < 0) {
        unsign_int(4294967295);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            a = nb % 10;
            nb = (nb - a) / 10;
            unsign_int(nb);
            my_putchar(a + 48);
        } else {
            my_putchar(nb + 48);
        }
    }
}

void decimal_hexa(unsigned int nb)
{
    unsigned int r;
    char *bin = malloc(sizeof(int) + 4294967296);

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    for (unsigned int i = 0; nb != 0; i++) {
        r = (nb % 16);
        nb = nb / 16;
        if (r < 10)
            bin[i] = (r + 48);
        if (r >= 10)
            bin[i] = ((r - 10) + 'a');
    }
    my_revstr(bin);
    my_putstr(bin);
    free(bin);
}

void decimal_hexa_maj(unsigned int nb)
{
    unsigned int r;
    char *bin = malloc(sizeof(int) + 4294967296);

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    for (unsigned int i = 0; nb != 0; i++) {
        r = (nb % 16);
        nb = nb / 16;
        if (r < 10)
            bin[i] = (r + 48);
        if (r >= 10)
            bin[i] = ((r - 10) + 'A');
    }
    my_revstr(bin);
    my_putstr(bin);
    free(bin);
}
