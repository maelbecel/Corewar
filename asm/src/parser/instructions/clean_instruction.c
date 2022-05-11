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

static void clear_space(instruction_t *instruction)
{
    while (instruction->next != NULL) {
        if (instruction->id == ID_SPACE && instruction->next->id == ID_SPACE)
            pop_next(instruction);
        else
            break;
    }
    if (instruction->next != NULL)
        clear_space(instruction->next);
}

static void clean_between_sep(instruction_t *instruction)
{
    while (instruction->next != NULL) {
        if (instruction->id == ID_SPACE &&
                                        instruction->next->id == ID_SEPARATOR)
            instruction = pop(instruction);
        else
            break;
    }
    if (instruction->next != NULL)
        clean_between_sep(instruction->next);
}

static void clean_after_sep(instruction_t *instruction)
{
    while (instruction->next != NULL) {
        if (instruction->id == ID_SEPARATOR &&
                                        instruction->next->id == ID_SPACE)
            pop_next(instruction);
        else
            break;
    }
    if (instruction->next != NULL)
        clean_after_sep(instruction->next);
}

void clean_instruction(instruction_t *instruction)
{
    instruction_t *last = go_to_last(instruction);

    if (!instruction)
        return;
    if (my_strlen(last->str) == 0) {
        last->prev->next = NULL;
        free(last->str);
        free(last);
    }
    clear_space(instruction);
    clean_between_sep(instruction);
    clean_after_sep(instruction);
}
