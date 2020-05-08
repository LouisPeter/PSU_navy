/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** get_info.c
*/

#include "include/my.h"
#include "include/my_navy.h"

char *get_position(void)
{
    char *buffer = NULL;
    int readed;
    char c = 0;
    while (1) {
        readed = read(0, &c, 1);
        if (readed <= 0)
            return (NULL);
        if (my_strlen(buffer) > 2)
            return ("F9");
        if (c == '\n')
            return (buffer);
        buffer = realloc_str(buffer, c);
    }

}

void send_coordinate(char *pos, int pid)
{
    int x_int = pos[0] - 'A' + 1;
    int y_int = pos[1] - '0';

    send_message(dec_bin(x_int), pid);
    send_message(dec_bin(y_int), pid);
}

void send_message(char *pid2, int pid1)
{
    for (int i = 0; pid2[i]; i++) {
        if (pid2[i] == '0')
            kill(pid1, SIGUSR1);
        if (pid2[i] == '1')
            kill(pid1, SIGUSR2);
        usleep(15000);
    }
}

int start_game(void)
{
    int message_int = 0;

    while (my_strlen(message) != 16)
        usleep(1000);
    message_int = convert_to_dec(message);
    free(message);
    message = NULL;
    return (message_int);
}

int receive_message(void)
{
    int message_int = 0;

    while (my_strlen(message) != 16)
        usleep(1000);
    message_int = convert_to_dec(message);
    free(message);
    message = NULL;
    return (message_int);
}
