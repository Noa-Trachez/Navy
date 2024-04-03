/*
** EPITECH PROJECT, 2021
** append_char
** File description:
** apeend_char
*/
#include "stdlib.h"
#include "../include/strmanip.h"

char *char_to_str(char c)
{
    char *result = malloc(2);

    result[0] = c;
    result[1] = '\0';
    return (result);
}

void append_char(char **str, char c, int is_free)
{
    char *tmp = *str;
    int len = my_strlen(tmp) + 1;
    char *new = malloc(sizeof(char) * (len + 1));

    my_strcpy(new, tmp);
    new[len - 1] = c;
    new[len] = '\0';
    if (is_free)
        free(tmp);
    *str = new;
}

void append(char **str, char *buf, int is_free)
{
    char *tmp = *str;
    int len = my_strlen(tmp) + my_strlen(buf);
    char *new = malloc(sizeof(char) * (len + 1));

    my_strcpy(new, tmp);
    my_strcat(new, buf);
    new[len] = '\0';
    if (is_free)
        free(tmp);
    *str = new;
}
