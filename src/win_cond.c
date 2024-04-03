/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-navy-quentin.desmettre
** File description:
** win_cond.c
*/

#include "navy.h"

int enemy_won(char **my_map)
{
    for (int i = 0; i < 8; i++)
        if (contain_any_of(my_map[i], "2345"))
            return 0;
    return 1;
}

int has_i_won(char **enemy_map)
{
    int nb_shot_enemy = 0;

    for (int i = 0; i < 8; i++)
        nb_shot_enemy += count_occurences('x', enemy_map[i]);
    return nb_shot_enemy >= 14;
}
