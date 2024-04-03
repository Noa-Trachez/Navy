/*
** EPITECH PROJECT, 2021
** my_concat_list
** File description:
** concatenates two lists
*/

#include "../../include/linked_list.h"

void concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *save = *begin1;

    while ((*begin1)->next)
        *begin1 = (*begin1)->next;
    (*begin1)->next = begin2;
    *begin1 = save;
}
