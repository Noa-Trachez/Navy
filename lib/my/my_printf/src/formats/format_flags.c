/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** get formats specifiers
*/

#include "my_printf.h"

int add_sign(char **str, params_t *params, char sign)
{
    char *tmp = char_to_str(sign);

    if (str[0][0] != '-' &&
    (params->specifier <= 1 || params->specifier == P))
        re_alloc(str, replace(*str, 0, 0, tmp), 1);
    if (str[0][0] != '-' && params->specifier >= LOW_F)
        re_alloc(str, replace(*str, 0, 0, tmp), 1);
    free(tmp);
    return 0;
}

char *insert_0x(char *str)
{
    char *new = my_strdup(str);

    re_alloc(&new, replace(new, 0, 0, "0x"), 1);
    free(str);
    return new;
}

int insert_0(char **str, params_t *params)
{
    char *zeros[3] = {"0", "0x", "0X"};

    if ((str[0][0] != '0' || str[0][1] == '0')
    && params->specifier >= 3 && params->specifier <= 5)
        re_alloc(str, replace(*str, 0, 0,
        zeros[params->specifier - 3]), 1);
    if (params->specifier >= LOW_F && index_of('.', *str) < 0)
        append_char(str, '.', 1);
    return 0;
}

char format_flags(char **str, params_t *params, char *pad_char)
{
    if (params->flags[0] && my_strlen(*str))
        insert_0(str, params);
    if (params->flags[1])
        add_sign(str, params, '+');
    else if (params->flags[2])
        add_sign(str, params, ' ');
    *pad_char = (params->flags[4] == 1) ? '0' : ' ';
    return (params->flags[3] == 1) ? PAD_LEFT : PAD_RIGHT;
}
