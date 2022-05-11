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

void add_node(instruction_t *node, instruction_t *node_add)
{
    instruction_t *old_next = node->next;

    node->next = node_add;
    node_add->prev = node;
    if (node_add != NULL)
        node_add->next = old_next;
    if (old_next != NULL)
        old_next->prev = node_add;
}

instruction_t *get_last_token(instruction_t *token)
{
    instruction_t *last_token = token;

    if (token == NULL) {
        return NULL;
    }
    if (token->next != NULL)
        last_token = get_last_token(token->next);
    return last_token;
}

int add_node_at_the_end(instruction_t *node_1, instruction_t *node_2)
{
    instruction_t *last_node = get_last_token(node_1);

    if (last_node == NULL) {
        return EXIT_ERROR;
    }
    add_node(last_node, node_2);
    return EXIT_SUCCESS;
}