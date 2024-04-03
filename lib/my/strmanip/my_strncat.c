/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** concatenates n characters
*/

#include "../include/strmanip.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int it = my_strlen(dest);

    for (int index = 0; index < nb && *src; index++, src++) {
        dest[it] = *src;
        it++;
    }
    dest[it] = 0;
    return dest;
}
