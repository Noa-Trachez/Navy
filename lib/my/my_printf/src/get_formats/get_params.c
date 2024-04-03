/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** get formats specifiers
*/

#include "my_printf.h"

void reset_params(params_t *params)
{
    params->specifier = 0;
    params->precision = 0;
    params->length = 0;
    params->width = 0;
    for (int i = 0; i < 5; i++)
        (params->flags)[i] = 0;
}

params_t new_params(void)
{
    params_t params;

    reset_params(&params);
    return params;
}

int get_flags_wid(char **dup, int i, int *offset, params_t *params)
{
    int len_width;

    if (dup[0][i + *offset] == 0) {
        re_alloc(dup, replace(*dup, i, dup[0][i] != 0, ""), 1);
        return BREAK;
    }
    *offset = get_flags(dup, i, params->flags);
    if (dup[0][i + *offset] == 0) {
        re_alloc(dup, replace(*dup, i, *offset, ""), 1);
        return BREAK;
    }
    params->width = get_width(*dup, i + *offset, &len_width);
    *offset += len_width;
    if (dup[0][i + *offset] == 0 || params->width < -1) {
        re_alloc(dup, replace(*dup, i, *offset, ""), 1);
        return BREAK;
    }
    return 0;
}

int get_pre_len_spe(char **dup, int i, int *offset, params_t *params)
{
    int len;

    params->precision = get_precision(dup, i + *offset, &len);
    *offset += len;
    if (dup[0][i + *offset] == 0 || params->precision < -1) {
        re_alloc(dup, replace(*dup, i, *offset + 1, ""), 1);
        return BREAK;
    }
    params->length = get_length(dup, i + *offset, &len);
    if (dup[0][i + *offset] == 0) {
        re_alloc(dup, replace(*dup, i, *offset, ""), 1);
        return BREAK;
    }
    params->specifier = get_specifier(dup, i + *offset);
    if (params->specifier == -1)
        return CONTINUE;
    re_alloc(dup, replace(*dup, i - 1, 2, ""), 1);
    return 0;
}

int get_all_infos(char **dup, int i, params_t *params)
{
    int offset = 0;
    int tmp = get_flags_wid(dup, i, &offset, params);

    if (tmp == BREAK)
        return BREAK;
    tmp = get_pre_len_spe(dup, i, &offset, params);
    if (tmp == BREAK)
        return BREAK;
    if (tmp == CONTINUE)
        return CONTINUE;
    return offset;
}
