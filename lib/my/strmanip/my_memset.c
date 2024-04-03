/*
** EPITECH PROJECT, 2021
** MY_MEMSET
** File description:
** Copies the char c to the first n characters of the string
*/

int init_with(char *str, int c, int n)
{
    for (int i = 0; i < n; i++)
        str[i] = c;
    return 0;
}
