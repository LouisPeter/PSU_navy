/*
** EPITECH PROJECT, 2018
** my_lib
** File description:
** my_putstr
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

int my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (0);
}
