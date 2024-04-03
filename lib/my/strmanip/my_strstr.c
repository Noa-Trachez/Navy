/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** finds first occurence in a string
*/

static int compare(char const *x, char const *y)
{
    while (*x && *y) {
        if (*x != *y) {
            return 0;
        }
        x++;
        y++;
    }
    return (*y == '\0');
}

char *my_strstr(char *x, char const *y)
{
    while (*x != '\0') {
        if ((*x == *y) && compare(x, y)) {
            return x;
        }
        x++;
    }
    return 0;
}
