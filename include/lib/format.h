/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** formats proto
*/

#ifndef INCLUDE_F_H
    #define INCLUDE_F_H
    #include "my_printf.h"

char *format_with(params_t *params, va_list *args);
int format_var(char **dup, char **to_print, va_list *args, int i);
int add_sign(char **str, params_t *params, char sign);
char *insert_0x(char *str);
int insert_0(char **str, params_t *params);
char format_flags(char **str, params_t *params, char *pad_char);
int format_precision_str(char **str, params_t *params);
int format_precision_int(char **str, params_t *params);
int format_precision(char **str, params_t *params);
int get_start(char **str, int len, int pad_dir);
char get_pad_char(params_t *params, char normal);
int format_width(char **str, params_t *params, char pad_chr, int pad_dir);

#endif
