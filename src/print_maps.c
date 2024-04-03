/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-navy-quentin.desmettre
** File description:
** print_maps.c
*/

#include "navy.h"

void print_pos(char **map, int type)
{
    print("%s positions:\n", type == 0 ? "my" : "enemy's");

    print(" |A B C D E F G H\n");
    print("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        print("%d|", i + 1);
        for (int j = 0; j < 8; j++) {
            print("%c", map[i][j]);
            print("%s", (j + 1 < 8) ? " " : "\n");
        }
    }
    print("\n");
}

void print_both_maps(char **my, char **enemy)
{
    print_pos(my, 0);
    print_pos(enemy, 1);
}
