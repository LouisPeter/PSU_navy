/*
** EPITECH PROJECT, 2018
** delivery
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/stat.h>
#include <signal.h>

void my_putchar(char c);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char *str);
int my_strlen(char const *str);
int my_isneg(int n);
int my_getnbr(char const *str);
char *my_revstr(char *str);
char *my_strcpy(char *dest, char *src);
char *my_strcat(const char *str, char *str2);
char *my_cat(char *dest, char const *src, int nb);
char *my_strdup(char const *str, char *str2);
char *my_strncpy(char *src, char *dest, int n);
char **my_str_to_word_array(char const *str);
char *clear_str(char *buff);

//----my_printf----//

void my_printf(char *pos, ...);
int flag(char *pos, va_list argptr);
int flagtwo(char *pos, va_list argptr);
int flagthree(char *pos, va_list argptr);
int flagfour(char *pos, va_list argptr);
int flagfive(char *pos, va_list argptr);
int flagsix(char *pos, va_list argptr);
void decimal_binary(unsigned int nb);
void decimal_octal(unsigned int nb);
void unsign_int(unsigned int nb);
void decimal_hexa(unsigned int nb);
void decimal_hexa_maj(unsigned int nb);
void the_string(char *str);
void *exa_point(unsigned long long p);

//----GET_NEXT_LINE----//

char *get_next_line(int fd);
char *my_realloc(char *str1, char *str2);
char *line_display(char *file, int incrementer);
char *get_the_file(int fd);

//----FEATURE_NAVY----//

int my_compute_power_rec(int nb, int p);
char *dec_bin(unsigned int nb);
int convert_to_dec(char *convert);
char **tab_cpy(char **tab);
int error_number(char *str);

#endif
