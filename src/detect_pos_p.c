/*
** EPITECH PROJECT, 2022
** position_du_player
** File description:
** player_position
*/
#include <stddef.h>
#include "struct.h"

int suite(char **tab, var_t *pos, int i, int j)
{
    if (tab[i][j] == 'P') {
        pos->x = i;
        pos->y = j;
        tab[i][j] = ' ';
    }
    return 0;
}

int detect_pos_p(char **tab, var_t *pos)
{
    int j = 0;
    int i = 0;

    for (i = 0; tab[i] != NULL; i++) {
        for (j = 0; tab[i][j] != '\0'; j++) {
            suite(tab, pos, i, j);
        }
        //j = 0;
    }
    return 0;
}
