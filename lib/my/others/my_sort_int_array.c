/*
** EPITECH PROJECT, 2021
** my_sort_int_array
** File description:
** sort an array of integers
*/

#include "../include/others.h"

static void sort(int *a, int *b)
{
    if (*a > *b) {
        my_int_swap(a, b);
    }
}

void my_sort_int_array(int *array, int size)
{
    for (int first = 0; first < size - 1; first++) {
        for (int second = first + 1; second < size; second++ ) {
            sort(&array[first], &array[second]);
        }
    }
}
