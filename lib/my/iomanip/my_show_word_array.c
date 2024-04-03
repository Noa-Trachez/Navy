/*
** EPITECH PROJECT, 2021
** my_show_word_array
** File description:
** display the content of an array of words
*/

#include "../include/iomanip.h"

int my_show_word_array(char * const *tab)
{
    while (*tab) {
        my_putstr(*tab);
        my_putchar('\n');
        tab++;
    }
    return 0;
}
