/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** get formats specifiers
*/

#include "my_printf.h"

char *cast_unsigned_dec(unsigned long var, int length)
{
    return cast_unsigned(var, DECIMAL, length);
}

char *cast_char(unsigned long var, int length)
{
    if (length == L)
        return wint_to_str((wint_t)var);
    else
        return char_to_str((int)var);
}

char *cast_str(unsigned long var, int length)
{
    if (length == L)
        return wchar_t_to_str((wchar_t *)var);
    else
        return my_strdup((char *)var);
}

char *cast_str_non_printable(unsigned long var, int length)
{
    if (length == L)
        return show_non_print_wchar((wchar_t *)var);
    else
        return show_non_print((char *)var);
}
