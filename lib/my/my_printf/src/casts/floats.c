/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** floats.c
*/

#include "my_printf.h"

char *float_to_str(long double var, int precision)
{
    long double ent = (long long)var;
    char *result = signed_to_str_base((long long)var, "0123456789");
    long double dec = var - ent;
    char *tmp;

    if (!(var == var)) {
        free(result);
        return my_strdup("NaN");
    }
    if (var < (long double)0)
        dec *= -1;
    append_char(&result, '.', 1);
    for (int i = 0; i < precision; i++) {
        dec *= (long double)10;
        tmp = signed_to_str_base((long long)dec, "0123456789");
        append(&result, tmp, 1);
        free(tmp);
        dec -= (long double)((long long)dec);
    }
    return result;
}

char *init_exp(long double *var, char *sign)
{
    int exp = 0;

    while (*var > (long double)10) {
        *var /= (long double)10;
        exp++;
    }
    if (*var < (long double)1) {
        *var *= (long double)10;
        exp--;
    }
    if (exp < 0) {
        exp *= -1;
        *sign = '-';
    }
    return signed_to_str_base(exp, "0123456789");
}

char *float_to_sc(long double var, int precision)
{
    char sign = '+';
    char *result;
    char *exp_str = 0;
    int neg = 0;

    if (var < (long double)0) {
        var *= -1;
        neg = 1;
    }
    exp_str = init_exp(&var, &sign);
    result = float_to_str(var, precision);
    append_char(&result, 'E', 1);
    append_char(&result, sign, 1);
    append(&result, exp_str, 1);
    if (neg)
        re_alloc(&result, replace(result, 0, 0, "-"), 1);
    return result;
}

char *cast_float(va_list *args, params_t *params)
{
    char *(*funcs[4])(long double, int) = {&float_to_str, &float_to_str,
    &float_to_sc, &float_to_sc};

    if (params->length == L_L)
        return funcs[params->specifier - 12](va_arg(*args, long double),
        (params->precision < 0) ? 6 : params->precision);
    else
        return funcs[params->specifier - 12](va_arg(*args, double),
        (params->precision < 0) ? 6 : params->precision);
}
