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

instruction_t *rm_node(instruction_t *deleted)
{
    instruction_t *new_node = deleted->next;

    if (new_node == NULL)
        return NULL;
    new_node->prev = deleted->prev;
    if (deleted->prev != NULL)
        deleted->prev->next = new_node;
    free(deleted->token);
    free(deleted);
    return new_node;
}
