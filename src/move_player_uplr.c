/*
** EPITECH PROJECT, 2022
** move_player_right_left
** File description:
** right_left_move
*/
#include "my.h"
#include <curses.h>
#include "struct.h"

int move_player_left(char **tab, var_t *pos)
{
    int i = pos->x; int j = pos->y;

    if (tab[i][j - 1] == '#')
        return 0;
    if (tab[i][j - 1] == 'X' && tab[i][j - 2] == '#')
        return 0;
    if (tab[i][j - 1] == 'X' && tab[i][j - 2] == 'X')
        return 0;
    if (tab[i][j - 1] == 'X' && tab[i][j - 2] == ' ') {
        tab[i][j - 2] = 'X';
        pos->y--;
        tab[i][j] = ' ';
    } else if (tab[i][j - 1] == 'X' && tab[i][j - 2] == 'O') {
        tab[i][j - 2] = 'X';
        pos->y--;
        tab[i][j] = ' ';
    } else {
        tab[i][j] = ' ';
        pos->y--;
    }
}

int move_player_right(char **tab, var_t *pos)
{
    int	i = pos->x; int	j = pos->y;

    if (tab[i][j + 1] == '#')
        return 0;
    if (tab[i][j + 1] == 'X' && tab[i][j + 2] == '#')
    return 0;
    if (tab[i][j + 1] == 'X' && tab[i][j + 2] == 'X')
        return 0;
    if (tab[i][j + 1] == 'X' && tab[i][j + 2] == ' ') {
        tab[i][j + 2] = 'X';
        pos->y++;
        tab[i][j] = ' ';
    } else if (tab[i][j + 1] == 'X' && tab[i][j + 2] == 'O') {
        tab[i][j + 2] = 'X';
        pos->y++;
        tab[i][j] = ' ';
    } else {
        tab[i][j] = ' ';
        pos->y++;
    }
}

int move_player_up(char **tab, var_t *pos)
{
    int i = pos->x; int j = pos->y;

    if (tab[i - 1][j] == '#')
        return 0;
    if (tab[i - 1][j] == 'X' && tab[i - 2][j] == '#')
    return 0;
    if (tab[i - 1][j] == 'X' && tab[i - 2][j] == 'X')
        return 0;
    if (tab[i - 1][j] == 'X' && tab[i - 2][j] == ' ') {
        tab[i - 2][j] = 'X';
        pos->x--;
        tab[i][j] = ' ';
    } else if (tab[i - 1][j] == 'X' && tab[i - 2][j] == 'O') {
        tab[i - 2][j] = 'X';
        pos->x--;
        tab[i][j] = ' ';
    } else {
        tab[i][j] = ' ';
        pos->x--;
    }
}

int move_player_down(char **tab, var_t *pos)
{
    int i = pos->x; int j = pos->y;

    if (tab[i + 1][j] == '#')
        return 0;
    if (tab[i + 1][j] == 'X' && tab[i + 2][j] == '#')
        return 0;
    if (tab[i + 1][j] == 'X' && tab[i + 2][j] == 'X')
        return 0;
    if (tab[i + 1][j] == 'X' && tab[i + 2][j] == ' ') {
        tab[i + 2][j] = 'X';
        pos->x++;
        tab[i][j] = ' ';
    } else if (tab[i + 1][j] == 'X' && tab[i + 2][j] == 'O') {
        tab[i + 2][j] = 'X';
    pos->x++;
        tab[i][j] = ' ';
    } else {
        tab[i][j] = ' ';
        pos->x++;
    }
}

int move_player(char **tab, var_t *pos, int get)
{
    if (get == KEY_LEFT)
        move_player_left(tab, pos);
    if (get == KEY_RIGHT)
        move_player_right(tab, pos);
    if (get == KEY_UP)
        move_player_up(tab, pos);
    if (get == KEY_DOWN)
        move_player_down(tab, pos);
}
