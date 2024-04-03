/*
** EPITECH PROJECT, 2021
** strmanip
** File description:
** Header for strmanip functions
*/

#ifndef INCLUDE_STRMANIP_H
    #define INCLUDE_STRMANIP_H

char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *x, char const *y);
char **my_str_to_word_array(char const *str, char const *delimiters);
int contain(char const *str, char const c);
int is_op(char const c);
int contain_any_of(char const *str, char const *check);
int contain_only(char const *str, char const *check);
char *replace(char const *str, int start, int nb, char *new);
int init_with(char *str, int c, int n);
char *char_to_str(char c);
void append_char(char **str, char c, int is_free);
int strlen_free(char *str);
void append(char **str, char *buf, int is_free);
int count_occurences(char const c, char const *str);
void re_alloc(char **str, char *new, int is_free);
int index_of(char c, char *str);

#endif
