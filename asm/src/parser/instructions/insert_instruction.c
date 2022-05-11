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

int insert_new_instruction(instruction_t *start, instruction_t *new)
{
    instruction_t *last_node = go_to_last(start);
    instruction_t *next = NULL;

    if (!last_node)
        return EXIT_ERROR;
    next = last_node->next;
    last_node->next = new;
    new->prev = last_node;
    if (new != NULL)
        new->next = next;
    if (next != NULL)
        next->prev = new;
    return EXIT_SUCCESS;
}
