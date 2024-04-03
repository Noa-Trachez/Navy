/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** get formats specifiers
*/

#include "my_printf.h"

int format_precision_str(char **str, params_t *params)
{
    if (params->precision >= 0 && my_strlen(*str) > params->precision)
        str[0][params->precision] = 0;
    return 0;
}

int format_precision_int(char **str, params_t *params)
{
    int pre = params->precision;
    int len = my_strlen(*str);
    char tmp[pre + 1];
    int isneg = (str[0][0] == '-') ? 1 : 0;
    int ishex = (len >= 2 && str[0][1] == 'x') ? 2 : 0;

    init_with(tmp, '0', pre);
    tmp[pre] = 0;
    if (str[0][0] == '0' && pre == 0) {
        str[0][0] = 0;
        return 0;
    }
    if (len - isneg - ishex < pre) {
        tmp[pre - len + isneg + ishex] = 0;
        re_alloc(str, replace(*str, isneg + ishex, 0, tmp), 1);
    }
    return 0;
}

int format_precision_float(char **str, params_t *params)
{
    int i_dot = index_of('.', str[0]);
    if (params->precision == 0 && i_dot > 0) {
        while (str[0][i_dot] && contain(".0123456789", str[0][i_dot]))
            re_alloc(str, replace(*str, i_dot, 1, ""), 1);
    }
    return 0;
}

int format_precision(char **str, params_t *params)
{
    int (*format[3])(char **, params_t *) =
    {&format_precision_int, &format_precision_str,
    &format_precision_float};

    if (params->specifier <= 6 || params->specifier == P)
        return format[0](str, params);
    else if (params->specifier <= 8)
        return format[1](str, params);
    if (params->specifier >= LOW_F)
        return format[2](str, params);
    return 0;
}
