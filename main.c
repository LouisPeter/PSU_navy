/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** main.c
*/

#include "include/my.h"
#include "include/my_navy.h"

void makeacpy(mnavy_t *mnavy)
{
    mnavy->m_cpy = tab_cpy(mnavy->map);

    for (int i = 0; mnavy->map[i] != NULL; i++) {
        for (int j = 1; mnavy->map[i][j] != '\0'; j++) {
            if (mnavy->map[i][j] == '2' || mnavy->map[i][j] == '3' ||
            mnavy->map[i][j] == '4' || mnavy->map[i][j] == '5') {
                mnavy->m_cpy[i][j] = '=';
            }
        }
    }
}

void make_the_map(mnavy_t *mnavy)
{
    char **map = malloc(sizeof(char*) * 11);
    int j = 0;
    int letter = -1;

    for (int i = 0; i < 10; i++)
        map[i] = malloc(sizeof(char*) * 18);
    for (int i = 0; i < 10; i++) {
        for (; j < 17; j++) {
            map = makeline(i, j, letter, map);
            letter += ((j % 2) == 0) ? 1 : 0;
            map[i][j + 1] = '\0';
        }
        map[i][j + 1] = '\0';
        j = 0;
    }
    map[10] = NULL;
    mnavy->map = map;
    mnavy->enemy_map = tab_cpy(map);
}

char **makeline(int i, int j, int letter, char **map)
{
    if (i == 0) {
        map[i][j] = ' ';
        if (j == 1)
            map[i][j] = '|';
        if ((j % 2) == 0 && j != 0)
            map[i][j] = ('A' + letter);
    }
    if (i == 1) {
        map[i][j] = '-';
        j == 1 ? map[i][j] = '+' : 0;
    }
    if (i > 1) {
        j == 0 ? map[i][j] = ('0' + i - 1) : 0;
        j == 1 ? map[i][j] = '|' : 0;
        if (j > 1 && (j % 2) == 0)
            map[i][j] = '.';
        if (j > 1 && (j % 2) == 1)
            map[i][j] = ' ';
    }
    return (map);
}

int start(int argc, char *argv[])
{
    int a = 0;
    mnavy_t *mnavy = malloc(sizeof(*mnavy));
    init_signal();
    if (argc == 2)
        a = put_pid(mnavy, argv[1]);
    if (argc == 3)
        a = connection(argv[1], argv[2], mnavy);
    return (a);
}

int main(int argc, char *argv[])
{
    int a = 0;
    message = NULL;
    if (argc < 2)
        return (84);
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        tiret_h();
        return (0);
    }
    a = start(argc, argv);
    return (a);
}
