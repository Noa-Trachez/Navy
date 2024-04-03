/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-navy-quentin.desmettre
** File description:
** map.c
*/

#include "navy.h"

int replace_in_double_array_by_char(char **buf, char a, char b, char *start)
{
    int (*function[5])(char **, char, char *) = {&fill_u_d, &fill_d_u,
    &fill_r_l, &fill_l_r};
    int dir = 0;
    int lenght = 0;

    if (a != 0) {
        dir = (a < 0) ? LEFT_TO_RIGHT : RIGHT_TO_LEFT;
        lenght = (a < 0) ? -a : a;
    } else {
        dir = (b < 0) ? UP_TO_DOWN : DOWN_TO_UP;
        lenght = (b < 0) ? -b : b;
    }
    lenght = function[dir](buf, lenght, start);
    return (lenght);
}

char **check_node_are_unique(char **map)
{
    char check_fir[8] = {map[0][2], map[0][3], map[1][2], map[1][3], map[2][2],
    map[2][3], map[3][2], map[3][3]};
    char check_sec[8] = {map[0][5], map[0][6], map[1][5], map[1][6], map[2][5],
    map[2][6], map[3][5], map[3][6]};
    char **buf = malloc(sizeof(char *) * 9);
    int check = 0;

    for (int i = 0; i < 8; i++)
        buf[i] = malloc(sizeof(char) * 9);
    buf[8] = NULL;
    fill_double_array_navy(buf);
    for (int i = 0; i < 4; i++) {
        check = replace_in_double_array_by_char(buf, check_fir[i * 2] -
        check_sec[i * 2], check_fir[i * 2 + 1] - check_sec[i * 2 + 1],
        map[i] + 2);
        if (check)
            return (0);
    }
    return (buf);
}

int fill_buff(FILE *fd, char **map)
{
    size_t bufsize = 0;
    char *buf = 0;
    int i = 0;

    while (1) {
        if (i == 4)
            break;
        getline(&buf, &bufsize, fd);
        map[i] = my_strdup(buf);
        i++;
    }
    if (getline(&buf, &bufsize, fd) > 0)
        return (84);
    else
        return (0);
}

char **check_map(char *file)
{
    FILE *fd = fopen(file, "r");
    char **map = malloc(sizeof(char *) * 5);
    int error = 0;
    map[4] = NULL;

    if (!fd)
        return (0);
    error += fill_buff(fd, map);
    fclose(fd);
    error += check_first_digit(map);
    for (int i = 0; i < 4; i++)
        error += check_len_line(map[i]);
    error += check_all_position(map);
    for (int i = 0; i < 4; i++)
        error += check_all_boat(map[i]);
    if (error)
        return (0);
    return (map);
}
