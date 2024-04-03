/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** get formats specifiers
*/

#include "my_printf.h"

int check_var(char **dup, char **to_print, va_list *args, int *i)
{
    int tmp = 0;

    if (dup[0][*i] == '%') {
        tmp = format_var(dup, to_print, args, *i);
        if (tmp == BREAK || tmp == CONTINUE)
            return tmp;
        *i = -1;
    } else
        append_char(to_print, dup[0][*i], 1);
    return 0;
}

char *get_printings(char const *format, va_list *args)
{
    char *to_print = my_strdup("");
    char *dup = my_strdup(format);
    int tmp;

    for (int i = 0; dup[i]; i++) {
        tmp = check_var(&dup, &to_print, args, &i);
        if (tmp == BREAK)
            break;
        if (tmp == CONTINUE)
            continue;
    }
    free(dup);
    return to_print;
}

int my_dprintf(int fd, char const *format, va_list *args)
{
    char *to_print = 0;
    int tmp;

    to_print = get_printings(format, args);
    tmp = write(fd, to_print, my_strlen(to_print));
    free(to_print);
    return tmp;
}

int dprint(int fd, char const *format, ...)
{
    va_list args;
    int tmp;

    va_start(args, format);
    tmp = my_dprintf(fd, format, &args);
    va_end(args);
    return tmp;
}

int print(char const *format, ...)
{
    va_list args;
    int tmp;

    va_start(args, format);
    tmp = my_dprintf(1, format, &args);
    va_end(args);
    return tmp;
}
