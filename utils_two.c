/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** main.c
*/

#include "include/my.h"
#include "include/my_navy.h"

void tiret_h(void)
{
    my_printf("%s\n", "USAGE");
    my_printf("%s\n", "     ./navy [first_player_pid] navy_positions");
    my_printf("%s\n", "DESCRIPTION");
    my_printf("%s", "     first_player_pid: only for the 2nd player. ");
    my_printf("%s\n", "pid of the first player.");
    my_printf("%s", "     navy_positions: file representing the positions ");
    my_printf("%s\n", "of the ships.");
}

int becareful_of_the_boat(char *m, int i)
{
    if (m[i] == '2') {
        if ((m[i+2]==m[i+5])&&((m[i+3]-m[i+6]==-1)||
        (m[i+3]-m[i+6]==1)));
        else if (m[i+3]==m[i+6]&&((m[i+2]-m[i+5]==-1)||
        (m[i+2]-m[i+5]==1)));
        else
            return (84);
    }
    if (m[i] == '3') {
        if ((m[i+2]==m[i+5])&&((m[i+3]-m[i+6]==-2)||
        (m[i+3]-m[i+6]==2)));
        else if (m[i+3]==m[i+6]&&((m[i+2]-m[i+5]==-2)||
        (m[i+2]-m[i+5]==2)));
        else
            return (84);
    }
    return (0);
}

int becareful_of_the_boat_two(char *m, int i)
{
    if (m[i] == '4') {
        if ((m[i+2]==m[i+5])&&((m[i+3]-m[i+6]==-3)||
        (m[i+3]-m[i+6]==3)));
        else if (m[i+3]==m[i+6]&&((m[i+2]-m[i+5]==-3)||
        (m[i+2]-m[i+5]==3)));
        else
            return (84);
    }
    if (m[i] == '5') {
        if ((m[i+2]==m[i+5])&&((m[i+3]-m[i+6]==-4)||
        (m[i+3]-m[i+6]==4)));
        else if (m[i+3]==m[i+6]&&((m[i+2]-m[i+5]==-4)||
        (m[i+2]-m[i+5]==4)));
        else
            return (84);
    }
    return (0);
}
