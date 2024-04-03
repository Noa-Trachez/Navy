/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-navy-quentin.desmettre
** File description:
** error.c
*/

#include "navy.h"

int check_first_digit(char **map)
{
    int check = 0;

    for (int i = 0; i < 4; i++) {
        if (map[i][0] == i + 50)
            check++;
        else
            check--;
    }
    return (check == 4 ? 0 : 84);
}

int check_len_line(char *map)
{
    int len = 0;

    for (; map[len]; len++);
    return (len != 8);
}

int check_all_boat(char *map)
{
    char first[2] = {map[2], map[3]};
    char second[2] = {map[5], map[6]};
    char diff_ref = map[0];
    int is_dif_first = 0;
    int is_dif_second = 0;

    is_dif_first = second[0] - first[0];
    is_dif_second = second[1] - first[1];
    if (is_dif_first && is_dif_second)
        return (84);
    if (is_dif_first < 0)
        is_dif_first *= -1;
    if (is_dif_second < 0)
        is_dif_second *= -1;
    if (is_dif_first == diff_ref - 49)
        return (0);
    if (is_dif_second == diff_ref - 49)
        return (0);
    return (84);
}

int trait_check_pos(char **map, int *range, char **check)
{
    if (contain(check[range[1]], map[range[0]][range[2]])) {
        range[1]++;
        if (range[1] == 4)
            range[1] = 1;
        return (0);
    } else
        return (84);
}

int check_all_position(char **map)
{
    char *all_char = "ABCDEFGH";
    char *all_nbr = "12345678";
    char *colomn = ":";
    char *check[8] = {all_nbr, colomn, all_char, all_nbr};
    int range[3] = {0, 0, 0};
    int error = 0;

    for (; range[0] < 4; range[0]++) {
        for (range[2] = 0; range[2] < 6; range[2]++) {
            error += trait_check_pos(map, range, check);
        }
    }
    return (error);
}
