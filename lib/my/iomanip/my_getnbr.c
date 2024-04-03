/*
** EPITECH PROJECT, 2021
** my_putnbr
** File description:
** cast string to integer
*/

static void sign_check(int *sign, char const *str, int *range)
{
    for (int i = 0; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-') {
            *sign *= -1;
        }
        *range = i + 1;
    }
}

static int nbr_check(char const *str, int *range, int *sign)
{
    int my_number = 0;
    for (int i = *range; str[i] >= '0' && str[i] <= '9'; i++) {
        if (my_number > (2147483648 - (str[i] - 48)) / 10) {
            return (-2);
        }
        if (*sign == 1 && my_number > (2147483647 - (str[i] - 48)) / 10) {
            return (-2);
        }
        my_number = (my_number * 10) + (str[i] - 48);
    }
    my_number *= *sign;
    return (my_number);
}

int my_getnbr(char const *str)
{
    int sign = 1;
    int range = 0;
    sign_check(&sign, str, &range);
    return nbr_check(str, &range, &sign);
}
