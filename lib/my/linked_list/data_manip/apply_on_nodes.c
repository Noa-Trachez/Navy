/*
** EPITECH PROJECT, 2021
** my_apply_on_nodes
** File description:
** Applies a function to each data in a linked list
*/

#include "../../include/linked_list.h"

int apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    while (begin) {
        (*f)(begin->data);
        begin = begin->next;
    }
    return 0;
}
