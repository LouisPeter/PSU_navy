/*
** EPITECH PROJECT, 2018
** PSU_my_ls_2018
** File description:
** strcaat custom with a
*/

#include "../../include/my.h"

char *my_cat(char *dest, char const *src, int nb)
{
    char *res = malloc(sizeof(char) *(nb + 1));
    int i = 0;
    int w = 0;

    while (dest[i] != '\0') {
        res[i] = dest[i];
        i++;
    }
    while (src[w] != '\0') {
        res[i + w] = src[w];
        w++;
    }
    res[i + w] = '\0';
    return (res);
}
