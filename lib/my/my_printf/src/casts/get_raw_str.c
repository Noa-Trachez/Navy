/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** get formats specifiers
*/

#include "my_printf.h"

char *cast_unsigned_oct(unsigned long var, int length)
{
    return cast_unsigned(var, OCTAL, length);
}

char *cast_unsigned_hexl(unsigned long var, int length)
{
    return cast_unsigned(var, HEXA_LOW, length);
}

char *cast_unsigned_hexu(unsigned long var, int length)
{
    return cast_unsigned(var, HEXA_UPP, length);
}

char *cast_unsigned_bin(unsigned long var, int length)
{
    return cast_unsigned(var, BINARY, length);
}

char *get_raw_formated_str(params_t *params, va_list *args)
{
    unsigned long var;
    char *(*funcs[10])() = {&cast_signed, &cast_unsigned_dec,
    &cast_unsigned_oct, &cast_unsigned_hexl, &cast_unsigned_hexu,
    &cast_unsigned_bin, &cast_str, &cast_str_non_printable, &cast_char,
    &cast_float};

    if (params->specifier == MOD)
        return my_strdup("%");
    if (params->specifier < LOW_F)
        var = va_arg(*args, unsigned long);
    if (params->specifier <= I)
        return funcs[0](var, params->length);
    if (params->specifier == P)
        return insert_0x(unsigned_to_str_base(var, HEXA_LOW));
    if (params->specifier >= LOW_F)
        return funcs[9](args, params);
    return funcs[params->specifier - 1](var, params->length);
}
