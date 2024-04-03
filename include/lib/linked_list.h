/*
** EPITECH PROJECT, 2021
** Day 11
** File description:
** linked list structure
*/

#ifndef MY_LIST_H
    #define MY_LIST_H
    #include <stdlib.h>

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;

int apply_on_matching_nodes(linked_list_t *begin,
    int (*f)(),
    void const *data_ref, int (*cmp)());
int apply_on_nodes(linked_list_t *begin, int (*f)(void *));
void concat_list(linked_list_t **begin1, linked_list_t *begin2);
int delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)());
linked_list_t *find_node(linked_list_t *begin,
    void const *data_ref, int (*cmp)());
int list_size(linked_list_t const *begin);
void merge_lists(linked_list_t **begin1, linked_list_t *begin2, int (*cmp)());
void rev_list(linked_list_t **begin);
void sort_list(linked_list_t **begin, int (*cmp)());
void insert_in_list(linked_list_t **begin, void *data, unsigned index);
void delete_single_node(linked_list_t **begin, unsigned index);
void add_in_sorted_list(linked_list_t **begin, void *data, int (*cmp)());
void append_node(linked_list_t **begin, void *data);

#endif
