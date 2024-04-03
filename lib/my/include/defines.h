/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** get formats specifiers
*/

#ifndef DEFINES_H
    #define DEFINES_H

    #define FORMAT_ERROR -1
    #define END_OF_STRING -10
    #define CONTINUE -3
    #define BREAK -2

    #define SPECIFIERS "diuoxXbsScp%fFeE"
    #define FLAGS "#+ -0"
    #define LENGTH "hljztL"

    #define NO_FLAGS 0

    #define D 0
    #define I 1
    #define U 2
    #define O 3
    #define LOW_X 4
    #define UPP_X 5
    #define B 6
    #define LOW_S 7
    #define UPP_S 8
    #define C 9
    #define P 10
    #define MOD 11
    #define LOW_F 12
    #define UPP_F 13
    #define LOW_E 14
    #define UPP_E 15
    #define INVALID_SPECIFIER -1

    #define HH 1
    #define H 2
    #define L 3
    #define LL 4
    #define J 5
    #define Z 6
    #define T 7
    #define L_L 8

    #define DECIMAL "0123456789"
    #define HEXA_LOW "0123456789abcdef"
    #define HEXA_UPP "0123456789ABCDEF"
    #define BINARY "01"
    #define OCTAL "01234567"

    #define PAD_RIGHT 1
    #define PAD_LEFT 0

#endif
