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

int rm_next_nodes(instruction_t *node)
{
    instruction_t *node_del = node->next;
    instruction_t *new_next = NULL;

    if (node_del == NULL) {
        return EXIT_ERROR;
    }
    if (node_del->next != NULL) {
        new_next = node_del->next;
        new_next->prev = node;
    }
    free(node_del->token);
    free(node_del);
    node->next = new_next;
    return EXIT_SUCCESS;
}
