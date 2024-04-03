/*
** EPITECH PROJECT, 2021
** linked_list
** File description:
** insert data at a given index
*/

#include "../../include/linked_list.h"

void insert_in_list(linked_list_t **begin, void *data, unsigned index)
{
    linked_list_t *new;
    linked_list_t *save = *begin;
    linked_list_t *prev = 0;

    for (unsigned i = 0; i < index; i++) {
        prev = *begin;
        *begin = (*begin)->next;
    }
    new = malloc(sizeof(linked_list_t));
    new->data = data;
    new->next = *begin;
    if (prev)
        prev->next = new;
    else
        save = new;
    *begin = save;
}
