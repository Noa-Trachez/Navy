/*
** EPITECH PROJECT, 2021
** linked_list
** File description:
** delete a node at a given index
*/

#include "../../include/linked_list.h"

void delete_single_node(linked_list_t **begin, unsigned index)
{
    linked_list_t *save = *begin;
    linked_list_t *prev = 0;

    for (unsigned i = 0; i < index; i++) {
        prev = *begin;
        *begin = (*begin)->next;
    }
    if (prev)
        prev->next = (*begin)->next;
    if (index == 0)
        save = (*begin)->next;
    free(*begin);
    *begin = save;
}
