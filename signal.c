/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** signal.c
*/

#include "include/my.h"
#include "include/my_navy.h"

void handle_usr_one(int sig)
{
    message = my_strcat(message, "0");
}

void handle_usr_two(int sig)
{
    message = my_strcat(message, "1");
}

void init_signal(void)
{
    signal(SIGUSR1, handle_usr_one);
    signal(SIGUSR2, handle_usr_two);
}
