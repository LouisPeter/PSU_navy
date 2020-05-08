/*
** EPITECH PROJECT, 2018
** my_lib
** File description:
** my_strdup
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "../../include/my.h"

char *my_strdup(char const *str, char *str2)
{
    int i = 0;

    for (; str[i]; i++);
    str2 = malloc(sizeof(char) * (i + 1));

    for (i = 0; str[i]; i++)
        str2[i] = str[i];
    str2[i] = '\0';
    return (str2);
}
