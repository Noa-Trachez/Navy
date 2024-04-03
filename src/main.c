/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-navy-quentin.desmettre
** File description:
** main.c
*/

#include "navy.h"

terminal_infos infos = {0, 0, -1, 0, 0, 0, 0, 0};

char **error_handling(int ac, char **av)
{
    if (ac == 1 || ac > 3)
        return (0);
    return (ac == 2 ? check_map(av[1]) : check_map(av[2]));
}

int main_loop(int ac, char **my_map, char **enemy_map)
{
    while (1) {
        if (ac == 2)
            print_both_maps(my_map, enemy_map);
        if (send_attack(enemy_map))
            return 84;
        usleep(1000);
        if (has_i_won(enemy_map))
            break;
        if (ac == 3)
            print_both_maps(my_map, enemy_map);
        if (get_attack(my_map))
            return 84;
        usleep(1000);
        if (enemy_won(my_map))
            break;
    }
    return 0;
}

int start_of_game(char **my_map, int ac)
{
    char *enemy_map[8] = { my_strdup("........"), my_strdup("........"),
    my_strdup("........"), my_strdup("........"), my_strdup("........"),
    my_strdup("........"), my_strdup("........"), my_strdup("........")};

    if (ac == 3) {
        print_both_maps(my_map, enemy_map);
        if (get_attack(my_map))
            return 84;
        usleep(1000);
    }
    if (main_loop(ac, my_map, enemy_map))
        return 84;
    print_both_maps(my_map, enemy_map);
    if (has_i_won(enemy_map)) {
        print("I won\n");
        return 0;
    } else {
        print("Enemy won\n");
        return 1;
    }
}

int main(int ac, char **argv)
{
    char **my_map = error_handling(ac, argv);
    char **tmp;

    if (!my_map) {
        dprint(2, "Invalid map\n");
        return (84);
    }
    tmp = check_node_are_unique(my_map);
    if (!tmp) {
        dprint(2, "Boat overlap\n");
        return (84);
    }
    free_double_array(my_map);
    my_map = tmp;
    infos.my_pid = getpid();
    print("my_pid: %d\n", infos.my_pid);
    if (connect(ac, argv))
        return 84;
    return (start_of_game(my_map, ac));
}
