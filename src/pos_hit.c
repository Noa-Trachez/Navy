/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-navy-quentin.desmettre
** File description:
** pos_hit.c
*/

#include "navy.h"

void free_double_array(char **tab)
{
    for (int i = 0; tab[i] != 0; i++)
        free(tab[i]);
    free(tab);
}

int is_hit(char const *pos, char **map)
{
    int col = pos[0] - 'A';
    int lin = pos[1] - '1';

    if (contain("2345", map[lin][col]))
        return 1;
    return 0;
}

int send_hit(char const *pos, char **map)
{
    int sig = is_hit(pos, map) ? SIGUSR1 : SIGUSR2;

    if (kill(infos.pair_pid, sig))
        return 84;
    usleep(1000);
    return 0;
}

void hit_handler(int id)
{
    infos.last_sig = id;

    if (id == SIGUSR1)
        infos.is_hit = 0;
    else if (id == SIGUSR2)
        infos.is_hit = 1;
}

int get_is_hit(void)
{
    struct sigaction s;

    s.sa_handler = hit_handler;
    s.sa_flags = SA_SIGINFO;
    s.sa_mask = (sigset_t){0};
    infos.last_sig = -1;
    sigaction(SIGUSR1, &s, NULL);
    sigaction(SIGUSR2, &s, NULL);
    pause();
    if (!IS_USR_SIG(infos.last_sig))
        return 84;
    return 0;
}
