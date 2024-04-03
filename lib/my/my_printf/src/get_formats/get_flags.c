/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** get formats specifiers
*/

#include "my_printf.h"

int check_others(char new_flag, flags_t flags)
{
    switch (new_flag) {
        case ' ':
            flags[2] = (flags[1] == 1) ? 0 : 1;
            flags[1] = !(flags[2]);
            break;
        case '0':
            flags[4] = (flags[3] == 1) ? 0 : 1;
            flags[3] = !(flags[4]);
            break;
    }
    return 0;
}

int actu_flags(char new_flag, flags_t flags)
{
    switch (new_flag) {
        case '#':
            flags[0] = 1;
            break;
        case '+':
            flags[1] = 1;
            flags[2] = 0;
            break;
        case '-':
            flags[3] = 1;
            flags[4] = 0;
            break;
        default:
            check_others(new_flag, flags);
    }
    return 0;
}

char *init_flags(flags_t flags)
{
    char *f = my_strdup("");

    if (flags[0])
        append_char(&f, '#', 1);
    if (flags[1])
        append_char(&f, '+', 1);
    else if (flags[2])
        append_char(&f, ' ', 1);
    if (flags[3])
        append_char(&f, '-', 1);
    else if (flags[4])
        append_char(&f, '0', 1);
    return f;
}

int get_flags(char **after_mod, int start, flags_t flags)
{
    char flag = 0;
    char *cleaned_flags;
    int nb_flags = 0;

    for (int i = start; contain(FLAGS, (*after_mod)[i]);) {
        flag = (*after_mod)[i];
        re_alloc(after_mod, replace(*after_mod, i, 1, ""), 1);
        actu_flags(flag, flags);
    }
    cleaned_flags = init_flags(flags);
    nb_flags = my_strlen(cleaned_flags);
    re_alloc(after_mod, replace(*after_mod, start, 0, cleaned_flags), 1);
    free(cleaned_flags);
    return nb_flags;
}
