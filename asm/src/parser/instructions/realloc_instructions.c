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

instruction_t **realloc_instructions(instruction_t **instructions, size_t size)
{
    instruction_t **new = malloc(sizeof(instruction_t *) * size);
    size_t pos = 0;

    if (!new)
        return NULL;
    for (; instructions[pos] != NULL; pos++)
        new[pos] = instructions[pos];
    for (; pos < size; pos++)
        new[pos] = NULL;
    free(instructions);
    return new;
}
