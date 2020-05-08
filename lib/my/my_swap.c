/*
** EPITECH PROJECT, 2018
** my_swap.c
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

void my_swap(int *a, int *b)
{
    int tem;
    tem = *a;
    *a = *b;
    *b = tem;
}
