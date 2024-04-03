/*
** EPITECH PROJECT, 2021
** B-PSU-101-LIL-1-1-navy-quentin.desmettre
** File description:
** allinclude.h
*/

#ifndef INCLUDE_ALL_H
    #define INCLUDE_ALL_H
    #include "lib/libmy.h"
    #include <errno.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <signal.h>
    #define IS_USR_SIG(x) (((x) == SIGUSR1) || ((x) == SIGUSR2))
    #define ERROR_T1_T2 "ERROR: Couldn't connect terminal 1 to terminal 2\n"
    #define ERROR_T2_T1 "ERROR: Couldn't connect terminal 2 to terminal 1\n"
    #define UP_TO_DOWN 0
    #define DOWN_TO_UP 1
    #define RIGHT_TO_LEFT 2
    #define LEFT_TO_RIGHT 3

// Global structure for signal handling
typedef struct {
    int my_pid;
    int pair_pid;
    int last_sig;
    int error_code;
    int nb_sig2;
    int i_col;
    int i_lin;
    int is_hit;
} terminal_infos;

extern terminal_infos infos;

// Argument's error handling
int fill_buff(FILE *fd, char **map);
char **check_map(char *file);
int check_first_digit(char **map);
int check_len_line(char *map);
int check_all_boat(char *map);
int trait_check_pos(char **map, int *range, char **check);
int check_all_position(char **map);
char **check_node_are_unique(char **map);

// Get coord from pair
void signal_handler(int id, siginfo_t *inf, void *);
void reset_infos_pos(void);
void init_sigaction_pos(struct sigaction *s);
char *infos_to_pos(void);
char *get_position_from_pair(void);

// Send coord to pair
int send_index_to_pair(int i);
int send_position_to_pair(char const *pos);

// Connect to pair
void send_connect(int id, siginfo_t *inf, void *);
void connect_t1_to_t2(void);
void get_last_signal(int sig, siginfo_t *s, void *);
int connect_t2_to_t1(int t1_pid);
int connect(int ac, char **av);

// Did we hit ?
int is_hit(char const *pos, char **map);
int send_hit(char const *pos, char **map);
void hit_handler(int id);
int get_is_hit(void);

// Update positions
int update_my_pos(char const *pos, char **map);
int update_enemy_pos(char const *pos, char **map);

// Send attack and get attacked
int get_attack(char **enemy_pos);
int send_attack(char **my_map);

// Send attack position
int send_index_to_pair(int index);
int send_position_to_pair(char const *pos);

// Print maps
void print_pos(char **map, int type);
void print_both_maps(char **my, char **enemy);

// Fill maps
void fill_double_array_navy(char **buf);
int fill_u_d(char **buf, char len, char *index);
int fill_d_u(char **buf, char len, char *index);
int fill_l_r(char **buf, char len, char *index);
int fill_r_l(char **buf, char len, char *index);

// la fonction a NOA
void free_double_array(char **a);

//Victory cond
int enemy_won(char **my_map);
int has_i_won(char **enemy_map);

#endif
