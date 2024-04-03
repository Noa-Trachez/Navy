/*
** EPITECH PROJECT, 2021
** my_delete_nodes
** File description:
** delete nodes that matches
*/

#include "../../include/linked_list.h"

int delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *save = *begin;
    linked_list_t *prev = 0;

    while (*begin) {
        if ((*cmp)((*begin)->data, data_ref) == 0 && prev) {
            prev->next = (*begin)->next;
            *begin = prev->next;
            continue;
        }
        if ((*cmp)((*begin)->data, data_ref) == 0 && !prev) {
            *begin = (*begin)->next;
            save = save->next;
            continue;
        }
        prev = *begin;
        *begin = (*begin)->next;
    }
    *begin = save;
    return 0;
}
