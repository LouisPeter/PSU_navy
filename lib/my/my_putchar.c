/*
** EPITECH PROJECT, 2018
** my_lib
** File description:
** my_putchar
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
