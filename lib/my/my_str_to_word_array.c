/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** __DESCRIPTION__
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"

char **my_str_to_word_array(char const *str)
{
    char **tab = malloc(sizeof(char *) * (my_strlen(str) + 1));
    int i = 0;
    int j = 0;
    int k = 0;
    int temp = 0;
    int pos = 0;

    while (str[i] != '\0') {
        for (;str[pos] >= 33 && str[pos] != '\0'; pos++, temp++);
        tab[j] = malloc(sizeof(char) * (temp + 1));
        for (;str[i] >= 33 && str[i] != '\0'; k++, i++)
            tab[j][k] = str[i];
        (str[i] != '\0') ? i += 1 : 0;
        j++;
        pos = i;
        temp = 0;
        k = 0;
    }
    return (tab);
}
