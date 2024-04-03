/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** get formats specifiers
*/

#include "my_printf.h"

int get_start(char **str, int len, int pad_dir)
{
    int starter = 0;

    if (pad_dir == PAD_RIGHT)
        starter = (len >= 2 &&
        (str[0][1] == 'x' || str[0][1] == 'X')) ? 2 : 0;
    else
        starter = len;
    return starter;
}

char get_pad_char(params_t *params, char normal)
{
    if (params->specifier <= 9 && params->specifier >= 7)
        return ' ';
    if (params->specifier <= 6 && params->precision >= 0)
        return ' ';
    return normal;
}

int format_width(char **str, params_t *params, char pad_chr, int pad_dir)
{
    int len = my_strlen(*str);
    char buffer[params->width];
    int starter = get_start(str, len, pad_dir);
    char pad_char = get_pad_char(params, pad_chr);

    init_with(buffer, pad_char, params->width);
    if (len < params->width) {
        buffer[params->width - len] = 0;
        re_alloc(str, replace(*str, starter, 0, buffer), 1);
    }
    return 0;
}
