/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-navy-quentin.desmettre
** File description:
** send_coord.c
*/

#include "navy.h"

int send_index_to_pair(int index)
{
    for (int i = 0; i < index; i++) {
        if (kill(infos.pair_pid, SIGUSR1))
            return 84;
        usleep(1000);
    }
    if (kill(infos.pair_pid, SIGUSR2))
        return 84;
    usleep(1000);
    return 0;
}

int send_position_to_pair(char const *pos)
{
    int col = pos[0] - 'A';
    int lin = pos[1] - '1';

    if (send_index_to_pair(col))
        return 84;
    if (send_index_to_pair(lin))
        return 84;
    return 0;
}
