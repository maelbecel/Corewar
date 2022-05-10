/*
** EPITECH PROJECT, 2022
** my_array_realloc
** File description:
** realloc an array
*/

#include "my.h"

char **my_array_realloc(char **tab)
{
    size_t size = my_array_len(tab);
    char **new = malloc(sizeof(char *) * (size + 2));

    if (!new)
        return NULL;
    for (size_t pos = 0; tab[pos] != NULL; pos++)
        new[pos] = my_strdup(tab[pos]);
    new[size] = NULL;
    new[size + 1] = NULL;
    my_free_2d_array(tab);
    return new;
}
