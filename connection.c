/*
** EPITECH PROJECT, 2018
** NAVY
** File description:
** connection.c
*/

#include "include/my.h"
#include "include/my_navy.h"

int put_pid(mnavy_t *mnavy, char *map)
{
    int a = 0;
    if (check_map(map, mnavy) == 84)
        return (84);
    mnavy->pid = malloc(sizeof(int) * 3);
    mnavy->pid[0] = getpid();
    my_printf("my_pid: %d\nwaiting for enemy connection...\n\n",
    mnavy->pid[0]);
    mnavy->pid[1] = start_game();
    mnavy->pid[2] = getpid();
    make_the_map(mnavy);
    game(mnavy);
    my_printf("enemy connected\n");
    mnavy->player = 1;
    a = game_first_player(mnavy);
    return (a);
}

int game_first_player(mnavy_t *mnavy)
{
    int a;
    int d;
    while (1) {
        print_the_maps(mnavy);
        d = game_recu_first(mnavy);
        if (d == 1)
            return (0);
        if (d == 84)
            return (84);
        if (checkthemaps(mnavy) == 1)
            break;
        game_recu_second(mnavy);
        if (checkthemaps(mnavy) == 1)
            break;
    }
    a = end_game(mnavy);
    return (a);
}

int connection(char *pid, char *map, mnavy_t *mnavy)
{
    int a = 0;
    mnavy->player = 2;
    if (check_map(map, mnavy) == 84)
        return (84);
    mnavy->pid = malloc(sizeof(int) * 3);
    int pid_player1 = my_getnbr(pid);
    char *pid2 = dec_bin(getpid());
    mnavy->pid[1] = getpid();
    make_the_map(mnavy);
    my_printf("my_pid: %d\n", mnavy->pid[1]);
    send_message(pid2, pid_player1);
    mnavy->pid[2] = pid_player1;
    my_printf("%s\n", "successfully connected");
    game(mnavy);
    a = game_second_player(mnavy);
    return (a);
}

int game_second_player(mnavy_t *mnavy)
{
    int a = 0;
    while (1) {
        print_the_maps(mnavy);
        game_recu_second(mnavy);
        if (checkthemaps(mnavy) == 1)
            break;
        if (game_recu_first(mnavy) == 84)
            return (84);
        if (checkthemaps(mnavy) == 1)
            break;
    }
    a = end_game(mnavy);
    return (a);
}

int checkthemaps(mnavy_t *mnavy)
{
    mnavy->game = 0;
    mnavy->enemy = 0;
    for (int i = 0; mnavy->map[i] != NULL; i++) {
        for (int j = 0; mnavy->map[i][j]!= '\0'; j++)
            mnavy->game += (mnavy->map[i][j] == 'x') ? 1 : 0;
    }
    for (int i = 0; mnavy->enemy_map[i] != NULL; i++) {
        for (int j = 0; mnavy->enemy_map[i][j] != '\0'; j++)
            mnavy->enemy += (mnavy->enemy_map[i][j] == 'x') ? 1 : 0;
    }
    if (mnavy->game == 14) {
        mnavy->end = 1;
        return (1);
    }
    if (mnavy->enemy == 14) {
        mnavy->end = 2;
        return (1);
    }
    return (0);
}
