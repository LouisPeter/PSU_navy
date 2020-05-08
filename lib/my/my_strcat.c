/*
** EPITECH PROJECT, 2018
** PSU_my_ls_2018
** File description:
** strcaat custom with a
*/
#include "../../include/my.h"

char *my_strcat(const char *str, char *str2)
{
    char *fin = malloc(sizeof(char) * (my_strlen(str) + my_strlen(str2) + 3));
    int j = 0;
    if (str == NULL)
        return (str2);

    for (int i = 0; str[i]; i++, j++)
        fin[j] = str[i];
    for (int i = 0; str2[i]; i++, j++)
        fin[j] = str2[i];
    fin[j] = '\0';
    return (fin);
}
