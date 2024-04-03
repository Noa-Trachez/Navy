/*
** EPITECH PROJECT, 2021
** my_sort_word_array
** File description:
** sort a word array
*/

#include "../include/strmanip.h"

static void my_own_sort(char **a, char **b)
{
    char *temp;

    if (my_strcmp(*a, *b) > 0) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

static void my_array_sort(char **array, int size)
{
    for (int first = 0; first < size - 1; first++) {
        for (int second = first + 1; second < size; second++) {
            my_own_sort(array + first, array + second);
        }
    }
}

int my_sort_word_array(char **tab)
{
    int len = 0;

    while (*(tab + len))
        len++;
    my_array_sort(tab, len);
    return 0;
}
