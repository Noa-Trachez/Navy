/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** duplicate a string
*/

#include "../include/strmanip.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *new_string = malloc(my_strlen(src) + 1);
    int index = 0;

    for (index = 0; index < my_strlen(src); ++index) {
        new_string[index] = src[index];
    }
    new_string[index] = '\0';
    return new_string;
}
