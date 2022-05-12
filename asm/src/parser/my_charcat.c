/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** return instructions array
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include "op.h"

char *my_charcat(char *str, char c)
{
    int size = my_strlen(str);
    char *new = malloc(sizeof(char) * (size + 2));

    if (!new)
        return NULL;
    my_strcpy(new, str);
    new[size] = c;
    new[size + 1] = '\0';
    free(str);
    return new;
}
