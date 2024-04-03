/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-navy-quentin.desmettre
** File description:
** fillmap.c
*/

#include "navy.h"

void fill_double_array_navy(char **buf)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            buf[i][j] = '.';
        buf[i][8] = '\0';
    }
}

int fill_u_d(char **buf, char len, char *index)
{
    int first_index = index[0] - 'A';
    int second_index = index[1] - '1';
    int lenght = len;

    for (int i = 0; i != lenght + 1; i++) {
        if (buf[second_index + i][first_index] != '.')
            return (84);
        buf[second_index + i][first_index] = len + '1';
    }
    return (0);
}

int fill_d_u(char **buf, char len, char *index)
{
    int first_index = index[0] - 'A';
    int second_index = index[1] - '1';
    int lenght = len;

    for (int i = lenght + 1; i > 0; i--) {
        if (buf[second_index - i + 1][first_index] != '.')
            return (84);
        buf[second_index - i + 1][first_index] = len + '1';
    }
    return (0);
}

int fill_l_r(char **buf, char len, char *index)
{
    int first_index = index[0] - 'A';
    int second_index = index[1] - '1';
    int lenght = len;

    for (int i = 0; i != lenght + 1; i++) {
        if (buf[second_index][first_index + i] != '.')
            return (84);
        buf[second_index][first_index + i] = len + '1';
    }
    return (0);
}

int fill_r_l(char **buf, char len, char *index)
{
    int first_index = index[0] - 'A';
    int second_index = index[1] - '1';
    int lenght = len;

    for (int i = lenght + 1; i > 0; i--) {
        if (buf[second_index][first_index - i + 1] != '.')
            return (84);
        buf[second_index][first_index - i + 1] = len + '1';
    }
    return (0);
}
