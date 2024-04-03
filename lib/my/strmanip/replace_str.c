/*
** EPITECH PROJECT, 2021
** rep.c
** File description:
** rep.c
*/
#include "../include/strmanip.h"
#include "../include/iomanip.h"
#include <stdlib.h>

void re_alloc(char **str, char *new, int is_free)
{
    char *tmp = *str;

    *str = new;
    if (is_free)
        free(tmp);
}

char *replace(char const *str, int from, int nb, char *new)
{
    int len = my_strlen(str) - nb + my_strlen(new);
    char *new_string = malloc(sizeof(char) * (len + 1));
    int len_new = my_strlen(new);

    if (from < 0)
        return my_strdup(str);
    for (int i = 0; i < from; i++) {
        new_string[i] = str[i];
    }
    for (int i = from; i < len_new + from; i++) {
        new_string[i] = new[i - from];
    }
    for (int i = from + len_new; str[i + nb - len_new]; i++) {
        new_string[i] = str[i + nb - len_new];
    }
    new_string[len] = '\0';
    return new_string;
}
