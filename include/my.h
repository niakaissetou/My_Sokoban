/*
** EPITECH PROJECT, 2022
** my_point_h
** File description:
** poiiiininnnttt_hh
*/

#ifndef MY_H_
    #define MY_H_
    #include "struct.h"
int verify_count_value(char **tab, char *buffer);
int check_win(char **tab, char **copy);
void my_putchar(char c);
void check_pos_o(char **tab, char **copy);
char *buffer(char *fileptath);
int detect_pos_p(char **tab, var_t *pos);
int detect_o(char **tab, var_t *pos);
int number_column(char *buffer);
int number_line(char *buffer);
int my_putstr(char const *str);
char **copy_of_tab(char *buffer);
char **create_tab(char *buffer);
char *display_map(char *filepath);
int move_player(char **tab, var_t *pos, int get);
#endif
