/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** Print a string
*/

#include "../include/strmanip.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    return write(1, str, my_strlen(str));
}

int my_putstr_error(char const *str)
{
    write(2, str, my_strlen(str));
    return 0;
}
