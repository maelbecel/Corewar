/*
** EPITECH PROJECT, 2022
** my_free_2d_array
** File description:
** free a 2d array
*/

#include "my.h"

void my_free_2d_array(char **tab)
{
    if (tab == NULL)
        return;
    for (size_t i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}
