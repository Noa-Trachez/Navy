/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** get formats specifiers
*/

#include "my_printf.h"

char *unsigned_to_str(unsigned long var, char *base)
{
    return unsigned_to_str_base((unsigned)var, base);
}

char *uchar_to_str(unsigned long var, char *base)
{
    return unsigned_to_str_base((unsigned char)var, base);
}

char *ushort_to_str(unsigned long var, char *base)
{
    return unsigned_to_str_base((unsigned short)var, base);
}

char *ulong_to_str(unsigned long var, char *base)
{
    return unsigned_to_str_base(var, base);
}

char *cast_unsigned(unsigned long var, char *base, int length)
{
    char *(*conv[4])(unsigned long, char *) = {&unsigned_to_str, &uchar_to_str,
    &ushort_to_str, &ulong_to_str};

    if (length <= 2)
        return conv[length](var, base);
    return conv[3](var, base);
}
