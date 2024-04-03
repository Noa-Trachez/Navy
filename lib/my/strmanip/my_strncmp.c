/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** compare s1 and s2 up to n bytes
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    while (n && *s1 && (*s1 == *s2)) {
        ++s1;
        ++s2;
        --n;
    }
    if (n == 0) {
        return 0;
    } else {
        return (*s1 - *s2);
    }
}
