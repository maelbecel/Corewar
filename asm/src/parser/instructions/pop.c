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

instruction_t *pop(instruction_t *instruction)
{
    instruction_t *new_node = instruction->next;

    if (!new_node)
        return NULL;
    new_node->prev = instruction->prev;
    if (instruction->prev != NULL)
        instruction->prev->next = new_node;
    free(instruction->str);
    free(instruction);
    return new_node;
}
