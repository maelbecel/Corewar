/*
** EPITECH PROJECT, 2021
** star.c
** File description:
** star.c
*/

#include <stddef.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (!src)
        return NULL;
    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
