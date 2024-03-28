/*
** EPITECH PROJECT, 2022
** initialise
** File description:
** la_structure
*/
#include "struct.h"
#include <curses.h>

var_t initialise(var_t var)
{
    var.get = getch();
    return var;
}
