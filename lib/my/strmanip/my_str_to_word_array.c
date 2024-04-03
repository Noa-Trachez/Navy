/*
** EPITECH PROJECT, 2021
** my_str_to_word_array
** File description:
** splits a string into words
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/strmanip.h"

static int count_words(char const *str, char const *delimiters)
{
    int counter = 0;
    int checker = 0;
    int increment = 1;

    while (*str) {
        if (!checker && !contain(delimiters, *str)) {
            checker = 1;
            counter++;
        }
        increment = 1;
        while (*str && contain(delimiters, *str)) {
            str++;
            checker = 0;
            increment = 0;
        }
        if (increment)
            str++;
    }
    return counter;
}

static int get_word_length(char const *str, char const *delimiters)
{
    int len = 0;

    while (!contain(delimiters, *(str + len)))
        len++;
    return len;
}

static char *get_word(char const *str, char const *delimiters)
{
    int length = get_word_length(str, delimiters);
    char *word = malloc(sizeof(char) * (length + 1));

    my_strncpy(word, str, length);
    word[length] = '\0';
    str += length;
    return word;
}

char **my_str_to_word_array(char const *str, char const *delimiters)
{
    int word_count = count_words(str, delimiters);
    char **array = malloc(sizeof(char *) * (word_count + 1));

    while (*str && contain(delimiters, *str))
        str++;
    for (int index = 0; index < word_count && *str; index++) {
        array[index] = get_word(str, delimiters);
        str += my_strlen(array[index]);
        while (*str && contain(delimiters, *str)) {
            str++;
        }
    }
    array[word_count] = 0;
    return array;
}
