/*
** EPITECH PROJECT, 2023
** check_win
** File description:
** my_sokoban_win
*/
#include <stdlib.h>

int suite_count_box_on_target(char **tab, char **copy, int i, int j)
{
    int a = 0;

    if (tab[i][j] == 'X' && copy[i][j] == 'O') {
        a++;
    }
    return a;
}

int suite_count_o(char **copy, int i, int j)
{
    int b = 0;

    if (copy[i][j] == 'O') {
        b++;
    }
    return b;
}

int count_box_on_targets(char **tab, char **copy)
{
    for (int i = 0; tab[i] != NULL; i++) {
    for (int j = 0; tab[i][j] != '\0'; j++) {
            suite_count_box_on_target(tab, copy, i, j);
        }
    }
}

int count_o(char **tab, char **copy)
{
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++) {
            suite_count_o(copy, i, j);
        }
    }
}

int check_win(char **tab, char **copy)
{
    if (count_o(tab, copy) == count_box_on_targets(tab, copy)) {
    } else
        return 0;
}
