/*
** EPITECH PROJECT, 2021
** my_rev_list
** File description:
** reverse a linked list
*/

#include "../../include/linked_list.h"

void rev_list(linked_list_t **begin)
{
    int length = list_size(*begin);
    linked_list_t *elements[length];
    linked_list_t **copy = begin;

    for (int i = 0; i < length; i++) {
        elements[i] = *copy;
        *copy = (*copy)->next;
    }
    for (int i = length - 1; i > 0; i--) {
        elements[i]->next = elements[i - 1];
    }
    elements[0]->next = 0;
    *begin = elements[length - 1];
}
