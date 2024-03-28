/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** putstr
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int t = 0;

    while (str[t]){
    my_putchar(str[t]);
    t = t + 1;
}
    return 0;
}
