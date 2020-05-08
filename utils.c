/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** utils.c
*/

#include "include/my.h"
#include "include/my_navy.h"

int check_map(char *map, mnavy_t *mnavy)
{
    int error = 0;
    int m = 1;
    int n = 0;
    map = get_file(map);
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n')
            n++;
    }
    for (int j = 0; map[j] != '\0'; j++, m++) {
        if (map[j] == '\n') {
            if (m != 8)
                return (84);
            m = 0;
        }
    }
    if (n != 3)
        return (84);
    error = check_map_bis(map);
    mnavy->f_map = map;
    return (error);
}

int check_map_bis(char *m)
{
    int i = 0;
    if (m[0] != '2' || m[8] != '3' || m[16] != '4' || m[24] != '5')
        return (84);
    while (i < 32) {
        if (m[i] < '2' || m[i] > '5')
            return (84);
        if ((m[i+1] != ':') || (m[i+4] != ':'))
            return (84);
        if ((m[i+2] < 'A' || m[i+2] > 'H') || (m[i+5] < 'A' || m[i+5] > 'H'))
            return (84);
        if ((m[i+3] < '0' || m[i+3] > '8') || (m[i+6] < '0' || m[i+6] > '8'))
            return (84);
        i += 8;
    }
    if (calc_map(m) == 84)
        return (84);
    return (0);
}

int calc_map(char *m)
{
    int a = 0;
    for (int i = 0; i < 32; i+=8) {
        if (becareful_of_the_boat(m, i) == 84)
            return (84);
        if (becareful_of_the_boat_two(m, i) == 84)
            return (84);
    }
    return (a);
}

void print_the_maps(mnavy_t *mnavy)
{
    my_printf("\nmy positions:\n");
    for (size_t i = 0; mnavy->map[i] != NULL; i++)
        my_printf("%s\n", mnavy->map[i]);
    my_printf("\nenemy's positions:\n");
    for (int i = 0; mnavy->enemy_map[i] != NULL; i++)
        my_printf("%s\n", mnavy->enemy_map[i]);
}

int end_game(mnavy_t *mnavy)
{
    int a = 0;
    if (mnavy->game == 14) {
        print_the_maps(mnavy);
        my_printf("\nEnemy won\n");
        a = 1;
    }
    if (mnavy->enemy == 14) {
        print_the_maps(mnavy);
        my_printf("\nI won\n");
        a = 0;
    }
    return (a);
}
