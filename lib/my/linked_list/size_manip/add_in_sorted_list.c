/*
** EPITECH PROJECT, 2021
** my_add_in_sorted_list
** File description:
** add an element in a sorted list
*/

#include "../include/linked_list.h"

void add_in_sorted_list(linked_list_t **begin, void *data, int (*cmp)())
{
    linked_list_t *new;

    new = malloc(sizeof(linked_list_t));
    new->data = data;
    new->next = *begin;
    *begin = new;
    sort_list(begin, cmp);
}
