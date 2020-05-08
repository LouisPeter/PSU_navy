/*
** EPITECH PROJECT, 2018
** PSU_my_ls_2018
** File description:
** strcaat custom with a
*/
#include "../../include/my.h"

char *clear_str(char *buff)
{
    for (int i = 0; buff[i] != '\0'; i++)
        buff[i] = '\0';
    return (buff);
}
