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

static void insert_instruction(instruction_t *src, instruction_t *new)
{
    instruction_t *old_next = src->next;

    src->next = new;
    new->prev = src;
    if (new != NULL)
        new->next = old_next;
    if (old_next != NULL)
        old_next->prev = new;
}

instruction_t *go_to_last(instruction_t *token)
{
    instruction_t *last_token = token;

    if (token == NULL)
        return NULL;
    if (token->next != NULL)
        last_token = go_to_last(token->next);
    return last_token;
}

int insert_new_instruction(instruction_t *start, instruction_t *new)
{
    instruction_t *last_node = go_to_last(start);

    if (!last_node)
        return EXIT_ERROR;
    insert_instruction(last_node, new);
    return EXIT_SUCCESS;
}
