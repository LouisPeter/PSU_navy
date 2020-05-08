/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

int my_getnbr(char const *str)
{
    int n = 0;
    int i = 0;

    if (str[i] == '-')
        i++;
    while (str[i] != '\0' && str[i] != '\n'){
        n = n + str[i] - 48;
        n = n * 10;
        i++;
    }
    n /= 10;
    if (str[0] == '-')
        return (-1 * n);
    else
        return (n);
}
