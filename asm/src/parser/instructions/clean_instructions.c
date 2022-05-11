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

static void clear_space(instruction_t *token)
{
    while (token->next != NULL) {
        if (token->id == ID_SPACE && token->next->id == ID_SPACE)
            rm_next_nodes(token);
        else
            break;
    }
    if (token->next != NULL)
        clear_space(token->next);
}

static void clean_between_sep(instruction_t *token)
{
    while (token->next != NULL) {
        if (token->id == ID_SPACE && token->next->id == ID_SEPARATOR)
            token = rm_node(token);
        else
            break;
    }
    if (token->next != NULL)
        clean_between_sep(token->next);
}

static void clean_after_sep(instruction_t *token)
{
    while (token->next != NULL) {
        if (token->id == ID_SEPARATOR && token->next->id == ID_SPACE)
            rm_next_nodes(token);
        else
            break;
    }
    if (token->next != NULL)
        clean_after_sep(token->next);
}

void clean_instructions(instruction_t *token)
{
    instruction_t *last = go_to_last(token);

    if (token == NULL)
        return;
    if (!my_strlen(last->token)) {
        last->prev->next = NULL;
        free(last->token);
        free(last);
    }
    clear_space(token);
    clean_between_sep(token);
    clean_after_sep(token);
}
