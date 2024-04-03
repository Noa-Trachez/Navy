/*
** EPITECH PROJECT, 2021
** my_sort_list
** File description:
** sort a list in ascending order
*/

#include "../../include/linked_list.h"

static void sort_by(linked_list_t *first, linked_list_t *second, int (*cmp)())
{
    void *tmp;

    if ((*cmp)(first->data, second->data) > 0) {
        tmp = first->data;
        first->data = second->data;
        second->data = tmp;
    }
}

void sort_list(linked_list_t **begin, int (*cmp)())
{
    linked_list_t *save = *begin;
    linked_list_t *first = *begin;
    linked_list_t *second;

    while (first) {
        second = first->next;
        while (second) {
            sort_by(first, second, cmp);
            second = second->next;
        }
        first = first->next;
    }
    *begin = save;
}
