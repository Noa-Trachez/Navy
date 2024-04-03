/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** get formats specifiers
*/

#include "my_printf.h"

char *signed_to_str(unsigned long var, char *base)
{
    return signed_to_str_base((int)var, base);
}

char *hh_to_str(unsigned long var, char *base)
{
    return signed_to_str_base((char)var, base);
}

char *short_to_str(unsigned long var, char *base)
{
    return signed_to_str_base((short)var, base);
}

char *long_to_str(unsigned long var, char *base)
{
    return signed_to_str_base((long)var, base);
}

char *cast_signed(unsigned long var, int length)
{
    char *(*conv[5])(unsigned long, char *) = {&signed_to_str, &hh_to_str,
    &short_to_str, &long_to_str, &ulong_to_str};

    if (length <= 2)
        return conv[length](var, DECIMAL);
    if (length <= 5)
        return conv[3](var, DECIMAL);
    return conv[4](var, DECIMAL);
}
