/*
** EPITECH PROJECT, 2018
** PSU_navy_2018
** File description:
** my_navy.h
*/

#ifndef MNAVY_H
#define MNAVY_H

char *message;

typedef struct mnavy_s
{
    char **map;
    char **enemy_map;
    char **m_cpy;
    char *f_map;
    int *pid;
    int player;
    int game;
    int enemy;
    int end;
} mnavy_t;

/*----------------------------------connection-----------------------------*/
int put_pid(mnavy_t *mnavy, char *map);
int connection(char *pid, char *map, mnavy_t *mnavy);
int checkthemaps(mnavy_t *mnavy);
int game_second_player(mnavy_t *mnavy);
int game_first_player(mnavy_t *mnavy);
/*----------------------------------game_recu-------------------------------*/
int game_recu_first(mnavy_t *mnavy);
void game_recu_second(mnavy_t *mnavy);
void hitbox(mnavy_t *mnavy, int x, int y);
void hitmap(mnavy_t *mnavy, char *buf, int hit);
void print_touch(int touch, mnavy_t *mnavy, char *buffer);
/*----------------------------------game---------------------------------*/
void game(mnavy_t *mnavy);
int if_game(mnavy_t *m, int checksens, int j, int i);
int if_game2(mnavy_t *m, int checksens, int j, int i);
int check_sens(mnavy_t *m, int i);
int calculate_size(mnavy_t *m, int checksens, int i);
/*----------------------------------getinfo---------------------------------*/
char *get_position(void);
void send_coordinate(char *pos, int pid);
void send_message(char *pid2, int pid1);
int start_game(void);
int receive_message(void);
/*------------------------------------main-----------------------------*/
void makeacpy(mnavy_t *mnavy);
void make_the_map(mnavy_t *mnavy);
char **makeline(int i, int j, int letter, char **map);
int start(int argc, char *argv[]);
/*----------------------------------open_file-----------------------------*/
int check(char *buff);
char *get_file(char *str);
char *realloc_str(char *str, char c);
/*----------------------------------signal---------------------------------*/
void handle_usr_one(int sig);
void handle_usr_two(int sig);
void init_signal(void);
/*----------------------------------utils----------------------------------*/
void print_the_maps(mnavy_t *mnavy);
int check_map(char *map, mnavy_t *mnavy);
int check_map_bis(char *map);
int calc_map(char *m);
int end_game(mnavy_t *mnavy);
/*------------------------------------utils2--------------------------------*/
void tiret_h(void);;
int becareful_of_the_boat(char *m, int i);
int becareful_of_the_boat_two(char *m, int i);
#endif /* MNAVY_H */
