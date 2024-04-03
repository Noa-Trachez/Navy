/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** Copy n chars from string to another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int index;

    for (index = 0; index < n && src[index]; index++) {
        dest[index] = src[index];
    }
    for (; index < n; index++) {
        dest[index] = '\0';
    }
    return dest;
}
