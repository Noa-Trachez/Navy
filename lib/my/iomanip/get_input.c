/*
** EPITECH PROJECT, 2021
** get_input
** File description:
** get input and display a message
*/

#include "iomanip.h"
#include <stdlib.h>
#include "strmanip.h"
#include <unistd.h>

char *get_input(char const *message)
{
    int c;
    char buf[4096];
    char *str;

    my_putstr(message);
    c = read(0, buf, 4096);
    if (c <= 0)
        return 0;
    buf[c - 1] = '\0';
    str = malloc(sizeof(char) * (c));
    str[0] = '\0';
    my_strcat(str, buf);
    return str;
}
