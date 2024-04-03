/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-navy-quentin.desmettre
** File description:
** coordinates.c
*/

#include "navy.h"

void signal_handler(int id, siginfo_t *inf, void *)
{
    if (inf->si_pid != infos.pair_pid)
        return;
    infos.last_sig = id;
    if (id == SIGUSR2) {
        usleep(10);
        infos.nb_sig2++;
        return;
    }
    usleep(10);
    if (id == SIGUSR1 && !infos.nb_sig2) {
        infos.i_col++;
    } else if (id == SIGUSR1 && infos.nb_sig2) {
        infos.i_lin++;
    }
}

void reset_infos_pos(void)
{
    infos.i_col = 0;
    infos.i_lin = 0;
    infos.nb_sig2 = 0;
    infos.last_sig = -1;
}

void init_sigaction_pos(struct sigaction *s)
{
    s->sa_sigaction = signal_handler;
    s->sa_flags = SA_SIGINFO;
    s->sa_mask = (sigset_t){0};
    sigaction(SIGUSR1, s, NULL);
    sigaction(SIGUSR2, s, NULL);
}

char *infos_to_pos(void)
{
    char *pos = malloc(sizeof(char) * 3);

    pos[0] = infos.i_col + 'A';
    pos[1] = infos.i_lin + '1';
    pos[2] = 0;
    return pos;
}

char *get_position_from_pair(void)
{
    struct sigaction s;

    init_sigaction_pos(&s);
    reset_infos_pos();
    while (infos.nb_sig2 != 2) {
        pause();
        if (!IS_USR_SIG(infos.last_sig))
            return 0;
        infos.last_sig = -1;
    }
    usleep(10);
    return infos_to_pos();
}
