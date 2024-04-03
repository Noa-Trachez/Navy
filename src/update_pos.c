/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-navy-quentin.desmettre
** File description:
** update_pos.c
*/

#include "navy.h"

int update_my_pos(char const *pos, char **map)
{
    int col = pos[0] - 'A';
    int lin = pos[1] - '1';
    if (get_is_hit())
        return 84;
    print("%s: %s\n\n", pos, !infos.is_hit ? "hit" : "missed");
    if (!contain("2345.", map[lin][col]))
        return 0;
    if (infos.is_hit)
        map[lin][col] = 'o';
    else
        map[lin][col] = 'x';
    return 0;
}

int update_enemy_pos(char const *pos, char **map)
{
    int col = pos[0] - 'A';
    int lin = pos[1] - '1';

    usleep(1000);
    if (send_hit(pos, map))
        return 84;
    print("%s: %s\n\n", pos, is_hit(pos, map) ? "hit" : "missed");
    if (!contain("2345.", map[lin][col]))
        return 0;
    if (is_hit(pos, map))
        map[lin][col] = 'x';
    else
        map[lin][col] = 'o';
    return 0;
}
