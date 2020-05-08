/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** game.c
*/

#include "include/my.h"
#include "include/my_navy.h"

int game_recu_first(mnavy_t *mnavy)
{
    char *buffer = NULL;
    int touch;
    my_printf("\nattack: ");
    buffer = get_position();
    if (buffer == NULL)
        return (1);
    if ((buffer[0]<'A' || buffer[0]>'H') || (buffer[1]<'1' || buffer[1]>'8')) {
        my_printf("wrong position\n");
        return (game_recu_first(mnavy));
    }
    if (buffer == NULL)
        return (84);
    send_coordinate(buffer, mnavy->pid[mnavy->player]);
    touch = receive_message();
    buffer[2] = '\0';
    print_touch(touch, mnavy, buffer);
    return (0);
}

void print_touch(int touch, mnavy_t *mnavy, char *buffer)
{
    if (touch == 0) {
        my_printf("%s : missed\n", buffer);
        hitmap(mnavy, buffer, 0);
    } else {
        if (mnavy->enemy_map[(buffer[1]-'0'+1)][((buffer[0]-'A')*2+2)] == 'x')
            my_printf("%s : missed\n", buffer);
        else
            my_printf("%s : hit\n", buffer);
        hitmap(mnavy, buffer, 1);
    }
}

void game_recu_second(mnavy_t *mnavy)
{
    int pos_y = 0;
    int pos_x = 0;
    my_printf("\n%s\n", "waiting for enemy's attack...");
    pos_x = receive_message();
    pos_y = receive_message();
    hitbox(mnavy, pos_x, pos_y);
}

void hitbox(mnavy_t *mnavy, int x, int y)
{
    x = x * 2;
    y = y + 1;
    char a;
    if (mnavy->m_cpy[y][x] == '=') {
        a = (x/2+64);
        my_printf("%c", a);
        if (mnavy->map[y][x] != 'x')
            my_printf("%d: hit\n", (y-1));
        else
            my_printf("%d: missed\n", (y-1));
        mnavy->map[y][x] = 'x';
        send_message("0000000000000001", mnavy->pid[mnavy->player]);
    } else {
        a = (x/2+64);
        my_printf("%c", a);
        my_printf("%d: missed\n", (y-1));
        mnavy->map[y][x] = 'o';
        send_message("0000000000000000", mnavy->pid[mnavy->player]);
    }
}

void hitmap(mnavy_t *mnavy, char *buf, int hit)
{
    if (hit == 0)
        mnavy->enemy_map[(buf[1] - '0' + 1)][((buf[0] - 'A') * 2 + 2)] = 'o';
    if (hit == 1)
        mnavy->enemy_map[(buf[1] - '0' + 1)][((buf[0] - 'A') * 2 + 2)] = 'x';
}
