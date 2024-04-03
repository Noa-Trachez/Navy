/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** compare 2 strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 && *s2) {
        if (*s1 > *s2)
            return 1;
        if (*s1 < *s2)
            return -1;
        ++s1;
        ++s2;
    }
    if (*s1 == *s2)
        return 0;
    if (*s1 == '\0')
        return -1;
    return 1;
}
