/*
** EPITECH PROJECT, 2018
** my_strncpy.c
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

char *my_strncpy(char *src, char *dest, int n)
{
    int i = 0;
    while (i < n) {
        dest[i] = src[i];
        i = i + 1;
        my_putchar(dest[i]);
    }
    dest[i] = '\0';
    return (dest);
}
