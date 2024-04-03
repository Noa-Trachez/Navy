/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** get_formats prot
*/

#ifndef INCLUDE_GET_FORMATS_H
    #define INCLUDE_GET_FORMATS_H
    #include "my_printf.h"

int check_others(char new_flag, flags_t flags);
int actu_flags(char new_flag, flags_t flags);
char *init_flags(flags_t flags);
int get_flags(char **after_mod, int start, flags_t flags);
int get_width(char *after_mod, int start, int *len);
int get_precision(char **after_mod, int i_dot, int *len);
int get_length(char **after_mod, int start, int *len_len);
int get_specifier(char **after_mod, int start);
void reset_params(params_t *params);
params_t new_params(void);
int get_flags_wid(char **dup, int i, int *offset, params_t *params);
int get_pre_len_spe(char **dup, int i, int *offset, params_t *params);
int get_all_infos(char **dup, int i, params_t *params);

#endif
