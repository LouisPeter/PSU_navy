/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_printf.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "../../include/my.h"

void my_printf(char *pos, ...)
{
    va_list argptr;
    va_start(argptr, pos);

    while (*pos != '\0') {
        if (*pos == '%'){
            *pos++;
            flag(pos, argptr);
        }
        else
            my_putchar(*pos);
        *pos++;
    }
    va_end(argptr);
}

int flag(char *pos, va_list argptr)
{
    if (*pos == 'c'){
        char c = va_arg(argptr, int);
        my_putchar(c);
    }
    else if (*pos == 's'){
        char *s = va_arg(argptr, char *);
        my_putstr(s);
    }
    flagtwo(pos, argptr);
}

int flagtwo(char *pos, va_list argptr)
{
    if (*pos == 'x'){
        unsigned int x = va_arg(argptr, unsigned int);
        decimal_hexa(x);
    }
    else if (*pos == 'X'){
        unsigned int X = va_arg(argptr, unsigned int);
        decimal_hexa_maj(X);
    }
    flagthree(pos, argptr);
}

int flagthree(char *pos, va_list argptr)
{
    if (*pos == '%'){
        write(1, "%", 1);
    }
    else if (*pos == 'o'){
        unsigned int oct = va_arg(argptr, unsigned int);
        decimal_octal(oct);
    }
    flagfour(pos, argptr);
}

int flagfour(char *pos, va_list argptr)
{
    if (*pos == 'S'){
        char *S = va_arg(argptr, char *);
        the_string(S);
    }
    else if (*pos == 'p'){
        unsigned long long p = va_arg(argptr, unsigned long long);
        exa_point(p);
    }
    flagfive(pos, argptr);
}
