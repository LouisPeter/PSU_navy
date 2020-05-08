/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_printf2.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "../../include/my.h"

int flagfive(char *pos, va_list argptr)
{
    if (*pos == 'd' || *pos == 'i') {
        int d = va_arg(argptr, int);
        my_put_nbr(d);
    }
    else if (*pos == 'b'){
        int b = va_arg(argptr, int);
        decimal_binary(b);
    }
    flagsix(pos, argptr);
}

int flagsix(char *pos, va_list argptr)
{
    if (*pos == 'u'){
        unsigned int u = va_arg(argptr, unsigned int);
        unsign_int(u);
    }
    return (0);
}
