/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "../../include/my.h"

int my_compute_power_rec(int nb, int p)
{
    int result;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    result = nb * my_compute_power_rec(nb, p - 1);
    return (result);
}

char *dec_bin(unsigned int nb)
{
    unsigned int r;
    char *bin = malloc(sizeof(char) + 128);
    unsigned int i = 0;
    if (nb == 0)
        return ("0");
    for (; nb != 0; i++) {
        r = (nb % 2);
        nb = nb / 2;
        bin[i] = (r + 48);
    }
    for (; i != 16; i++)
        bin[i] = '0';
    bin[i] = '\0';
    my_revstr(bin);
    return (bin);
}

int convert_to_dec(char *convert)
{
    int result = 0;

    for (int i = my_strlen(convert) - 1, power = 0; i > 0; i--, power++)
        result += (convert[i] == '1') ? my_compute_power_rec(2, power) : 0;
    return (result);
}

char **tab_cpy(char **tab)
{
    char **new = malloc(sizeof(char*) * 11);
    int j = 0;

    for (int i = 0; i < 10; i++)
        new[i] = malloc(sizeof(char*) * 18);
    for (int i = 0; i < 10; i++) {
        for (; j < 17; j++) {
            new[i][j] = tab[i][j];
            new[i][j + 1] = '\0';
        }
        new[i][j + 1] = '\0';
        j = 0;
    }
    new[10] = NULL;
    return (new);
}

int error_number(char *str)
{
    for (int i = 0; str[i]; i++) {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '\n');
        else
            return (84);
    }
    return (0);
}
