/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** realloc instructions array
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include "op.h"

instruction_t **realloc_instruction_array(instruction_t **tab, size_t size)
{
    instruction_t **new = malloc(sizeof(instruction_t *) * size);
    size_t i = 0;

    if (!new)
        return NULL;
    for (; tab[i] != NULL; i++)
        new[i] = tab[i];
    new[i] = NULL;
    free(tab);
    return new;
}
