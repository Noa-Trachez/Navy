/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-navy-quentin.desmettre
** File description:
** send_get_attack.c
*/

#include "navy.h"

int get_attack(char **enemy_pos)
{
    char *pair_pos;

    print("waiting for enemy's attack...\n");
    pair_pos = get_position_from_pair();
    if (!pair_pos) {
        dprint(2, "ERROR: could not get pair position\n");
        return 84;
    }
    if (pair_pos[0] > 'H' || pair_pos[0] < 'A' ||
    pair_pos[1] > '8' || pair_pos[1] < '1') {
        dprint(2, "ERROR: Pair sent an invalid position\n");
        return 84;
    }
    update_enemy_pos(pair_pos, enemy_pos);
    free(pair_pos);
    return 0;
}

int is_position_valid(char const *pos)
{
    if (my_strlen(pos) != 2)
        return 0;
    if (!contain("ABCDEFGH", pos[0]) ||
        !contain("12345678", pos[1]))
        return 0;
    return 1;
}

int continue_send_attack(char *my_pos, char **my_map)
{
    if (send_position_to_pair(my_pos)) {
        dprint(2, "ERROR: could not send position to pair\n");
        return 84;
    }
    update_my_pos(my_pos, my_map);
    free(my_pos);
    return 0;
}

int send_attack(char **my_map)
{
    char *my_pos;
    int valid = 0;

    while (!valid) {
        my_pos = get_input("attack: ");
        if (!my_pos) {
            dprint(2, "ERROR: could not get input\n");
            return 84;
        }
        valid = is_position_valid(my_pos);
        if (!valid)
            print("wrong position\n");
    }
    usleep(10);
    return (continue_send_attack(my_pos, my_map));
}
