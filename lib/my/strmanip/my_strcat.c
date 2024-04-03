/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** concatenates 2 strings
*/

#include "../include/strmanip.h"

char *my_strcat(char *dest, char const *src)
{
    int it = my_strlen(dest);

    while (*src) {
        dest[it] = *src;
        src++;
        it++;
    }
    dest[it] = '\0';
    return dest;
}
