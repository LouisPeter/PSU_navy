/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** get_next_line.c
*/

#include "get_next_line.h"
#include "../../include/my.h"

char *my_realloc(char *str1, char *str2)
{
    char *temp;
    int i = 0;
    int j = 0;

    if (str1 == NULL)
        return (NULL);
    temp = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
    if (!temp)
        return (NULL);
    while (str2 != NULL && str2[i] != '\0') {
        temp[i] = str2[i];
        i++;
    }
    while (str1[j] != '\0') {
        temp[i] = str1[j];
        i++;
        j++;
    }
    temp[i] = '\0';
    return (temp);
}

char *line_display(char *file, int incrementer)
{
    int index_line = 0;
    int i = incrementer;
    char *line = NULL;

    for (; file[i] != '\n' && file[i]; i++);
    line = malloc(sizeof(char) * (i - incrementer + 1));
    if (!line)
        return (NULL);
    while (i > incrementer) {
        line[index_line] = file[incrementer];
        index_line++;
        incrementer++;
    }
    line[index_line] = '\0';
    return (line);
}

char *get_the_file(int fd)
{
    char buffer[READ_SIZE + 1];
    char *file = NULL;
    int readed = 0;

    while ((readed = read(fd, buffer, READ_SIZE)) > 0) {
        buffer[readed] = '\0';
        if ((file = my_realloc(buffer, file)) == NULL)
            return (NULL);
        if (readed < READ_SIZE)
            return (file);
    }
    return (file);
}

char *get_next_line(int fd)
{
    static char *file = NULL;
    static int incrementer = 0;
    char *line;

    if (incrementer == 0)
        if ((file = get_the_file(fd)) == NULL)
            return (NULL);
    if (my_strlen(file) < incrementer)
        return (NULL);
    if ((line = line_display(file, incrementer)) == NULL)
        return (NULL);
    incrementer += my_strlen(line) + 1;
    return (line);
}
