/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-navy-quentin.desmettre
** File description:
** connection.c
*/

#include "navy.h"

void send_connect(int id, siginfo_t *inf, void *)
{
    if (id != SIGUSR1)
        return;
    if (kill(inf->si_pid, SIGUSR1)) {
        infos.error_code = 84;
    } else {
        infos.pair_pid = inf->si_pid;
        infos.last_sig = id;
    }
}

void connect_t1_to_t2(void)
{
    struct sigaction s;

    s.sa_sigaction = send_connect;
    s.sa_flags = SA_SIGINFO;
    s.sa_mask = (sigset_t){0};
    sigaction(SIGUSR1, &s, NULL);
    pause();
}

void get_last_signal(int sig, siginfo_t *s, void *)
{
    if (s->si_pid != infos.pair_pid)
        infos.error_code = 84;
    infos.last_sig = sig;
}

int connect_t2_to_t1(int t1_pid)
{
    struct sigaction s;

    infos.last_sig = -1;
    infos.pair_pid = t1_pid;
    s.sa_sigaction = get_last_signal;
    s.sa_flags = SA_SIGINFO;
    s.sa_mask = (sigset_t){0};
    sigaction(SIGUSR1, &s, NULL);
    if (kill(t1_pid, SIGUSR1))
        return 84;
    usleep(1000);
    if (infos.last_sig == -1)
        pause();
    if (infos.last_sig != SIGUSR1)
        return 84;
    return 0;
}

int connect(int ac, char **av)
{
    if (ac == 2) {
        print("waiting for enemy connection...\n\n");
        connect_t1_to_t2();
        if (infos.error_code)
            return dprint(2, ERROR_T1_T2) ? 84 : 84;
        else
            return print("enemy connected\n\n") ? 0 : 0;
    } else {
        if (!contain_only(av[1], "0123456789") || my_getnbr(av[1]) < 0)
            return 84;
        if (connect_t2_to_t1(my_getnbr(av[1])))
            return dprint(2, ERROR_T2_T1) ? 84 : 84;
        else if (infos.error_code)
            return dprint(2, "ERROR: Signal received from unknown process\n")
            ? 84 : 84;
        else
            return print("successfully connected\n\n") ? 0 : 0;
    }
}
