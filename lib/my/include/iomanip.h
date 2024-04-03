/*
** EPITECH PROJECT, 2021
** iomanip
** File description:
** input/output manipulations
*/

#ifndef INCLUDE_IOMANIP_H
    #define INCLUDE_IOMANIP_H

char *get_input(char const *message);
int my_getnbr_base(char const *str, char const *base);
int my_getnbr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_putstr_error(char const *str);
int my_show_word_array(char * const *tab);

#endif
