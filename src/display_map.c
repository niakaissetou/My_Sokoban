/*
** EPITECH PROJECT, 2022
** display_map
** File description:
** display_in_terminal
*/
#include <curses.h>
#include <sys/stat.h>
#include "my.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char **copy_of_tab(char *buffer)
{
    char **copy;
    int a = 0;
    int j = 0;
    int nb_lines = number_line(buffer);
    int nb_col = number_column(buffer);

    copy = malloc(sizeof(char *) * (nb_lines + 1));
    for (int i = 0; i < nb_lines; i++) {
        copy[i] = malloc(sizeof(char) * (nb_col + 1));
        for (; j < nb_col; j++) {
            copy[i][j] = buffer[a];
            a++;
        }
        copy[nb_lines] = NULL;
        j = 0;
        a++;
    }
    return copy;
}

char **create_tab(char *buffer)
{
    char **tab;
    int a = 0;
    int j = 0;
    int nb_lines = number_line(buffer);
    int nb_col = number_column(buffer);

    tab = malloc(sizeof(char *) * (nb_lines + 1));
    for (int i = 0; i < nb_lines; i++) {
        tab[i] = malloc(sizeof(char) * (nb_col + 1));
        for (; j < nb_col; j++) {
            tab[i][j] = buffer[a];
            a++;
        }
        tab[nb_lines] = NULL;
        j = 0;
        a++;
    }
    return tab;
}

void check_suite(char **tab, char **copy, int i, int j)
{
    if (tab[i][j] == ' ' && copy[i][j] == 'O') {
        tab[i][j] = 'O';
    }
}

void check_pos_o(char **tab, char **copy)
{
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++) {
            check_suite(tab, copy, i, j);
        }
    }
}

char *buffer(char *filepath)
{
    struct stat st;
    int fd, rd;
    char *buf;
    stat(filepath, &st);
    buf = malloc(sizeof(char *) * st.st_size);
    fd = open(filepath, O_RDONLY);
    rd = read(fd, buf, st.st_size);
    buf[st.st_size] = '\0';
    return buf;
}
