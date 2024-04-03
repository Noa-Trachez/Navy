/*
** EPITECH PROJECT, 2021
** my_find_node
** File description:
** find a node in a linked list
*/

#include "../../include/linked_list.h"

linked_list_t *find_node(linked_list_t *begin,
    void const *data_ref, int (*cmp)())
{
    while (begin) {
        if ((*cmp)(begin->data, data_ref) == 0)
            return begin;
        begin = begin->next;
    }
    return 0;
}
