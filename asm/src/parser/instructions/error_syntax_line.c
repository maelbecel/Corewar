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

int find_index_op(char *mnemonique)
{
    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (!my_strcmp(mnemonique, op_tab[i].mnemonique))
            return i;
    }
    return -1;
}

static instruction_t *check_label(instruction_t *cursor)
{
    if (cursor->next == NULL) {
        return NULL;
    } else if (cursor->next->id == ID_LABEL) {
        if (char_list_in_str(cursor->token, LABEL_CHARS))
            return NULL;
        if (cursor->next->next == NULL)
            return cursor->next;
        cursor = cursor->next->next;
        if (cursor->id != ID_SPACE)
            return NULL;
        cursor = cursor->next;
    }
    if (cursor == NULL)
        return NULL;
    return cursor;
}

int error_syntax_line(instruction_t *token)
{
    int index = 0;
    instruction_t *cursor = token;

    cursor = check_label(cursor);
    if (cursor == NULL)
        return EXIT_ERROR;
    if (cursor->id == ID_LABEL)
        return EXIT_SUCCESS;
    index = find_index_op(cursor->token);
    if (index == -1)
        return EXIT_ERROR;
    cursor = cursor->next;
    if (cursor == NULL ||
        (cursor->id != ID_SPACE && cursor->id != ID_SEPARATOR))
        return EXIT_ERROR;
    cursor = cursor->next;
    if (cursor == NULL)
        return EXIT_ERROR;
    return error_params(cursor);
}
