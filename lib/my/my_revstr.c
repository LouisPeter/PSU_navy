/*
** EPITECH PROJECT, 2018
** my_lib
** File description:
** my_revstr
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char c;
    i = my_strlen(str);

    while (j < (i - 1)) {
        c = str[j];
        str[j] = str[i - 1];
        str[i - 1] = c;
        i--;
        j++;
    }
    return (str);
}
