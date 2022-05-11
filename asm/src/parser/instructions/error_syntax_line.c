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

int get_op(char *mnemonique)
{
    for (size_t pos = 0; op_tab[pos].mnemonique != NULL; pos++) {
        if (my_strcmp(mnemonique, op_tab[pos].mnemonique) == 0)
            return pos;
    }
    return -1;
}

static instruction_t *check_label(instruction_t *cursor)
{
    if (!cursor->next)
        return NULL;
    else if (cursor->next->id == ID_LABEL) {
        if (char_list_in_str(cursor->str, LABEL_CHARS))
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
    index = get_op(cursor->str);
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
