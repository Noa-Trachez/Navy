/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** casts proto
*/

#ifndef ______INCLUDE_CASTS_H
    #define ______INCLUDE_CASTS_H
    #include "my_printf.h"

char *cast_unsigned_dec(unsigned long var, int length);
char *cast_unsigned_oct(unsigned long var, int length);
char *cast_unsigned_hexl(unsigned long var, int length);
char *cast_unsigned_hexu(unsigned long var, int length);
char *cast_unsigned_bin(unsigned long var, int length);
char *get_raw_formated_str(params_t *params, va_list *args);
char *signed_to_str(unsigned long var, char *base);
char *hh_to_str(unsigned long var, char *base);
char *short_to_str(unsigned long var, char *base);
char *long_to_str(unsigned long var, char *base);
char *cast_signed(unsigned long var, int length);
char *cast_char(unsigned long var, int length);
char *cast_str(unsigned long var, int length);
char *cast_str_non_printable(unsigned long var, int length);
char *unsigned_to_str(unsigned long var, char *base);
char *uchar_to_str(unsigned long var, char *base);
char *ushort_to_str(unsigned long var, char *base);
char *ulong_to_str(unsigned long var, char *base);
char *cast_unsigned(unsigned long var, char *base, int length);
char *signed_to_str_base(long long nb, char const *base);
char *unsigned_to_str_base(unsigned long long nb, char const *base);
char *wint_to_str(wint_t ch);
char *wchar_t_to_str(wchar_t *str);
char *float_to_str(long double var, int precision);
char *init_exp(long double *var, char *sign);
char *float_to_sc(long double var, int precision);
char *cast_float(va_list *args, params_t *params);

#endif
