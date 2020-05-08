/*
** EPITECH PROJECT, 2019
** my_getfile
** File description:
** getting file
*/

#include "include/my.h"
#include "include/my_navy.h"

int check(char *buff)
{
    int a = 0;

    for (int i = 0; i != - 1; i--) {
        if (buff[i] == '\0')
            a = 84;
    }
    return (a);
}

char *get_file(char *str)
{
    int file = open(str, O_RDONLY);
    int nb = 1;
    char *buffer = malloc(sizeof(char) * 1);
    char *buff = malloc(sizeof(char) * 2);

    buffer[0] = '\0';
    read(file, buff, 1);
    buff[1] = '\0';
    buffer = my_cat(buffer, buff, nb);
    while (check(buff) != 84) {
        buff = clear_str(buff);
        read(file, buff, 1);
        buff[1] = 0;
        nb++;
        buffer = my_cat(buffer, buff, nb);
    }
    buffer[my_strlen(buffer)-1] = '\0';
    return (buffer);
}

char *realloc_str(char *str, char c)
{
    char *tmp = NULL;
    int size = my_strlen(str);

    tmp = malloc((size + 2) * sizeof(char));
    if (str != NULL)
        for (int i = 0; str[i]; i++)
            tmp[i] = str[i];
    tmp[size] = c;
    tmp[size + 1] = '\0';
    free(str);
    return (tmp);
}
