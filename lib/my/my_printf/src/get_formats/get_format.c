/*
** EPITECH PROJECT, 2021
** B-PSU-100-LIL-1-1-myprintf-quentin.desmettre
** File description:
** get_format.c
*/

#include "my_printf.h"

int get_width(char *after_mod, int start, int *len)
{
    char *result = my_strdup("");
    int width = 0;

    for (int i = start; after_mod[i] &&
        contain("0123456789", after_mod[i]); i++) {
        append_char(&result, after_mod[i], 1);
    }
    *len = my_strlen(result);
    if (*len == 0) {
        free(result);
        return 0;
    }
    width = my_getnbr(result);
    free(result);
    return width;
}

int get_precision(char **after_mod, int i_dot, int *len)
{
    int precision = 0;

    *len = 0;
    if (after_mod[0][i_dot] != '.')
        return -1;
    if (!contain(DECIMAL, (*after_mod)[i_dot + 1])) {
        re_alloc(after_mod, replace(*after_mod, i_dot + 1, 0, "0"), 1);
        *len = 2;
        return 0;
    }
    precision = get_width(*after_mod, i_dot + 1, len);
    *len += 1;
    return precision;
}

int get_length(char **after_mod, int start, int *len_len)
{
    char length[3] = {after_mod[0][start], 0, 0};
    char *length_ofi[8] = {"hh", "h", "l", "ll", "j", "z", "t", "L"};
    int rvalue = -1;
    *len_len = 0;

    if (contain(SPECIFIERS, length[0]) || length[0] == 0)
        return 0;
    *len_len = 1;
    if (!contain(LENGTH, length[0]))
        return 0;
    re_alloc(after_mod, replace(*after_mod, start, 1, ""), 1);
    if (after_mod[0][start] && length[0] == after_mod[0][start]) {
        length[1] = after_mod[0][start];
        re_alloc(after_mod, replace(*after_mod, start, 1, ""), 1);
        *len_len += 1;
    }
    for (int i = 0; i < 8; i++)
        if (my_strcmp(length, length_ofi[i]) == 0)
            rvalue = i + 1;
    return rvalue;
}

int get_specifier(char **after_mod, int start)
{
    if (after_mod[0][start] == 0)
        return END_OF_STRING;
    return index_of(after_mod[0][start], SPECIFIERS);
}
