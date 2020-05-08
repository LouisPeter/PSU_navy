/*
** EPITECH PROJECT, 2018
** my_isneg.c
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
        my_putchar('\n');
    } else {
        my_putchar('N');
        my_putchar('\n');
    }
    return (0);
}
