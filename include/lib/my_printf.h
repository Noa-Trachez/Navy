/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** Header for my_printf
*/

#ifndef INCLUDE_MY_PRINTF_H
    #define INCLUDE_MY_PRINTF_H
    #include "strmanip.h"
    #include "iomanip.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdint.h>
    #include <stddef.h>
    #include <stdarg.h>
    #include <unistd.h>
    #include <wchar.h>

typedef int flags_t[5];

typedef struct params {
    flags_t flags;
    int width;
    int precision;
    int length;
    int specifier;
} params_t;

typedef union {
    unsigned long bits;
    double d;
} mine;

    #include "get_formats.h"
    #include "defines.h"
    #include "casts.h"
    #include "format.h"

int check_var(char **dup, char **to_print, va_list *args, int *i);
int my_dprintf(int fd, char const *format, va_list *args);
int dprint(int fd, char const *format, ...);
int print(char const *format, ...);
char *get_oct_ascii(char c);
char *show_non_print_wchar(wchar_t *str);
char *show_non_print(char *str);

#endif
