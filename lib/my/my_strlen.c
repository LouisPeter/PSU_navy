/*
** EPITECH PROJECT, 2018
** my_lib
** File description:
** my_strlen
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;
    if (str == NULL)
        return (0);
    while (str[i])
        i++;
    return (i);
}
