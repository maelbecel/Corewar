/*
** EPITECH PROJECT, 2022
** my_array_len
** File description:
** return the len of an array
*/

#include "my.h"

size_t my_array_len(char **tab)
{
    size_t size = 0;

    for (; tab[size] != NULL; size++);
    return size;
}
