/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** game.c
*/

#include "include/my.h"
#include "include/my_navy.h"

void game(mnavy_t *mnavy)
{
    int checksens;
    int size;
    for (int i = 0; i < 32; i+=8) {
        checksens = check_sens(mnavy, i);
        size = calculate_size(mnavy, checksens, i);
        for (int j = 0; size >= 0; size--) {
            j = if_game(mnavy, checksens, j, i);
        }
    }
    makeacpy(mnavy);
}

int if_game(mnavy_t *m, int checksens, int j, int i)
{
    if (checksens == 0 && i == 0)
        m->map[(m->f_map[i+3]-'0'+1)-j][(m->f_map[i+2]-'A')*2+2] = '2';
    if (checksens == 1 && i == 0)
        m->map[(m->f_map[i+3]-'0'+1)+j][(m->f_map[i+2]-'A')*2+2] = '2';
    if (checksens == 2 && i == 0)
        m->map[m->f_map[i+3]-'0'+1][((m->f_map[i+2]-'A')*2+2)+j] = '2';
    if (checksens == 3 && i == 0)
        m->map[m->f_map[i+3]-'0'+1][((m->f_map[i+2]-'A')*2+2)-j] = '2';
    if (checksens == 0 && i == 8)
        m->map[(m->f_map[i+3]-'0'+1)-j][(m->f_map[i+2]-'A')*2+2] = '3';
    if (checksens == 1 && i == 8)
        m->map[(m->f_map[i+3]-'0'+1)+j][(m->f_map[i+2]-'A')*2+2] = '3';
    if (checksens == 2 && i == 8)
        m->map[m->f_map[i+3]-'0'+1][((m->f_map[i+2]-'A')*2+2)+j] = '3';
    if (checksens == 3 && i == 8)
        m->map[m->f_map[i+3]-'0'+1][((m->f_map[i+2]-'A')*2+2)-j] = '3';
    if (checksens == 0 && i == 16)
        m->map[(m->f_map[i+3]-'0'+1)-j][(m->f_map[i+2]-'A')*2+2] = '4';
    j = if_game2(m, checksens, j, i);
    return (j);
}

int if_game2(mnavy_t *m, int checksens, int j, int i)
{
    if (checksens == 1 && i == 16)
        m->map[(m->f_map[i+3]-'0'+1)+j][(m->f_map[i+2]-'A')*2+2] = '4';
    if (checksens == 2 && i == 16)
        m->map[m->f_map[i+3]-'0'+1][((m->f_map[i+2]-'A')*2+2)+j] = '4';
    if (checksens == 3 && i == 16)
        m->map[m->f_map[i+3]-'0'+1][((m->f_map[i+2]-'A')*2+2)-j] = '4';
    if (checksens == 0 && i == 24)
        m->map[(m->f_map[i+3]-'0'+1)-j][(m->f_map[i+2]-'A')*2+2] = '5';
    if (checksens == 1 && i == 24)
        m->map[(m->f_map[i+3]-'0'+1)+j][(m->f_map[i+2]-'A')*2+2] = '5';
    if (checksens == 2 && i == 24)
        m->map[m->f_map[i+3]-'0'+1][((m->f_map[i+2]-'A')*2+2)+j] = '5';
    if (checksens == 3 && i == 24)
        m->map[m->f_map[i+3]-'0'+1][((m->f_map[i+2]-'A')*2+2)-j] = '5';
    if (checksens == 0 || checksens == 1)
        j++;
    if (checksens == 2 || checksens == 3)
        j+=2;
    return (j);
}

int check_sens(mnavy_t *m, int i)
{
    int sens;
    if (m->f_map[i+2] == m->f_map[i+5] && m->f_map[i+3] < m->f_map[i+6])
        sens = 0;
    if (m->f_map[i+2] == m->f_map[i+5] && m->f_map[i+3] > m->f_map[i+6])
        sens = 1;
    if (m->f_map[i+2] > m->f_map[i+5] && m->f_map[i+3] == m->f_map[i+6])
        sens = 2;
    if (m->f_map[i+2] < m->f_map[i+5] && m->f_map[i+3] == m->f_map[i+6])
        sens = 3;
    return (sens);
}

int calculate_size(mnavy_t *m, int checksens, int i)
{
    int s = 0;
    if (checksens == 0)
        for (; m->f_map[i+3] < m->f_map[i+6]; s++, m->f_map[i+3]++);
    if (checksens == 1)
        for (; m->f_map[i+6] < m->f_map[i+3]; s++, m->f_map[i+6]++);
    if (checksens == 2)
        for (; m->f_map[i+5] < m->f_map[i+2]; s++, m->f_map[i+5]++);
    if (checksens == 3)
        for (; m->f_map[i+2] < m->f_map[i+5]; s++, m->f_map[i+2]++);
    return (s);
}
