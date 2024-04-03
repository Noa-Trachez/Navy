/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** get formats specifiers
*/

#include "my_printf.h"

long long get_min(void)
{
    long min = __LONG_MAX__;

    min *= -1;
    min--;
    return min;
}

char *signed_to_str_base(long long nb, char const *base)
{
    char *str = "";
    long len = my_strlen(base);
    int neg = 0;
    int i = 0;

    if (nb == get_min())
        return my_strdup("-9223372036854775808");
    if (nb < 0) {
        nb *= -1;
        neg = 1;
    }
    for (i = 0; nb >= len; i++) {
        append_char(&str, base[nb % len], i);
        nb /= len;
    }
    append_char(&str, base[nb % len], i);
    if (neg)
        append_char(&str, '-', 1);
    return my_revstr(str);
}

char *unsigned_to_str_base(unsigned long long nb, char const *base)
{
    char *str = "";
    unsigned long len = my_strlen(base);
    int i = 0;

    for (i = 0; nb >= len; i++) {
        append_char(&str, base[nb % len], i);
        nb /= len;
    }
    append_char(&str, base[nb % len], i);
    return my_revstr(str);
}

char *wint_to_str(wint_t ch)
{
    if (ch > 127)
        return (char *)BREAK;
    return char_to_str(ch);
}

char *wchar_t_to_str(wchar_t *str)
{
    str = 0;
    str = str;
    return (char *)BREAK;
}
