/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** return the string in double quote
*/

#include "my.h"

size_t count_occur(char *str, char c)
{
    size_t nbr_occur = 0;

    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            nbr_occur++;
    }
    return nbr_occur;
}
