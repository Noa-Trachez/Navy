/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** Copy string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int it;

    for (it = 0; src[it]; ++it) {
        dest[it] = src[it];
    }
    dest[it] = src[it];
    return dest;
}
