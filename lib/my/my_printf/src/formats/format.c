/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** get formats specifiers
*/

#include "my_printf.h"

char *format_with(params_t *params, va_list *args)
{
    char *str = get_raw_formated_str(params, args);
    char padder = 0;
    int pad_dir = PAD_RIGHT;

    if (str == (char *)BREAK)
        return str;
    if (params->specifier == P)
        if (!my_strcmp(str, "0x0")) {
            free(str);
            return my_strdup("(nil)");
        }
    if (!my_strcmp(str, "%"))
        return str;
    format_precision(&str, params);
    pad_dir = format_flags(&str, params, &padder);
    format_width(&str, params, padder, pad_dir);
    return str;
}

int format_var(char **dup, char **to_print, va_list *args, int i)
{
    params_t params = new_params();
    int tmp = get_all_infos(dup, i + 1, &params);
    char *to_add;

    if (tmp == BREAK)
        return BREAK;
    if (tmp == CONTINUE) {
        append_char(to_print, '%', 1);
        return CONTINUE;
    }
    to_add = format_with(&params, args);
    if (to_add == (char *)BREAK)
        return BREAK;
    append(to_print, to_add, 1);
    re_alloc(dup, my_strdup(*dup + i + tmp), 1);
    free(to_add);
    return tmp;
}
