/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** Function that displays the number given as a parameter
*/

#include "../include/iomanip.h"

static void show_extrem_min(void)
{
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

static void do_recursion_part(int nb)
{
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    } else {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb == -2147483648) {
        show_extrem_min();
        return (0);
    }
    do_recursion_part(nb);
    return (0);
}
