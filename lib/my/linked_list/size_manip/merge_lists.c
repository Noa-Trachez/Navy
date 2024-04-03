/*
** EPITECH PROJECT, 2021
** my_merge
** File description:
** merge two sorted lists
*/

#include "../../include/linked_list.h"

void merge_lists(linked_list_t **begin1, linked_list_t *begin2, int (*cmp)())
{
    while (begin2) {
        add_in_sorted_list(begin1, begin2->data, cmp);
        begin2 = begin2->next;
    }
}
