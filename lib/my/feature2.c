/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** feature2
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "../../include/my.h"

void the_string(char *str)
{
    unsigned int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 32 && str[i] < 123)
            my_putchar(str[i]);
        else if (str[i] < 32 || str[i] > 123){
            my_putchar(92);
            i++;
        }
        i++;
    }
}

void *exa_point(unsigned long long p)
{
    unsigned int r;
    char *bin = malloc(sizeof(int) + 4294967296);
    if (p < 0) {
        my_putchar('-');
        p = p * (-1);
    }
    for (unsigned int i = 0; p != 0; i++) {
        r = (p % 16);
        p = p / 16;
        if (r < 10)
            bin[i] = (r + 48);
        if (r >= 10)
            bin[i] = ((r - 10) + 'a');
    }
    my_revstr(bin);
    my_putstr("0x");
    my_putstr(bin);
    free(bin);
}
