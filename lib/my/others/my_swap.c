/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** Swap 2 integers
*/

void my_int_swap(int *a, int *b)
{
    *a = (*a) + (*b);
    *b = (*a) - (*b);
    *a = (*a) - (*b);
}

void my_char_swap(char *a, char *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
