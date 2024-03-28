/*
** EPITECH PROJECT, 2022
** the_main_for_soko
** File description:
** sokosokoban
*/
#include "my.h"
#include "struct.h"
#include <curses.h>
#include <fcntl.h>
#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++) {
    }
    return (i);
}

int main_next(int ac, char **av)
{
    if (ac != 2)
        return 84;
    var_t pos; char *buff = buffer(av[1]);
    char **tab = create_tab(buff);
    char **copy = copy_of_tab(buff);
    detect_pos_p(tab, &pos); int key;
    initscr(); noecho(); curs_set(0);
    keypad(stdscr, TRUE);
    while (1) {
        for (int b = 0; tab[b] != NULL; b++) {
            printw("%s\n", tab[b]);
            check_pos_o(tab, copy);
        }
        mvprintw(pos.x, pos.y, "P");
        key = getch();
        move_player(tab, &pos, key);
        clear();
        check_win(tab, copy);
    }
    endwin();
}

void display_usage(int ac, char **av)
{
        my_putstr("USAGE\n");
        my_putstr("     ./my_sokoban map\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("     map file representing");
        my_putstr(" the warehouse map, containing '#' for walls,\n");
        my_putstr("         'P' for the player,");
        my_putstr(" 'X' for boxes and 'O' for storage locations.\n");
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    int fd = open(av[1], O_RDONLY);
    if (av[1][0] == '-' && av[1][1] == 'h')
        display_usage(ac, av);
    if (fd == -1)
        return 84;
    char *buf = buffer(av[1]);
    if (my_strlen(buf) == 0)
        return 84;
    main_next(ac, av);
}
