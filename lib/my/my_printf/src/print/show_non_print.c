/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** get formats specifiers
*/

#include "my_printf.h"

char *get_oct_ascii(char c)
{
    char *str = unsigned_to_str_base(c, OCTAL);
    char *zeros[5] = {"", "0", "00", "000", 0};

    if (my_strlen(str) < 3)
        re_alloc(&str, replace(str, 0, 0, zeros[3 - my_strlen(str)]), 1);
    re_alloc(&str, replace(str, 0, 0, "\\"), 1);
    return str;
}

char *show_non_print_wchar(wchar_t *str)
{
    str = 0;
    str = str;
    return (char *)BREAK;
}

char *show_non_print(char *str)
{
    char *value = my_strdup(str);
    char *tmp_oct = 0;

    for (int i = 0; value[i]; i++)
        if (value[i] < 32 || value[i] > 126) {
            tmp_oct = get_oct_ascii(value[i]);
            re_alloc(&value, replace(value, i, 1, tmp_oct), 1);
            free(tmp_oct);
        }
    return value;
}
