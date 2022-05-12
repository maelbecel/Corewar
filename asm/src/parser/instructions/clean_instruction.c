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
        if (instruction->type == T_SPACE && instruction->next->type == T_SPACE)
            pop_next(instruction);
        else
            break;
    }
    if (instruction->next != NULL)
        clear_space(instruction->next);
}

static void clear_current(instruction_t *instruction)
{
    while (instruction->next != NULL) {
        if (instruction->type == T_SPACE &&
                                        instruction->next->type == T_SEPARATOR)
            instruction = pop(instruction);
        else
            break;
    }
    if (instruction->next != NULL)
        clear_current(instruction->next);
}

static void clear_next(instruction_t *instruction)
{
    while (instruction->next != NULL) {
        if (instruction->type == T_SEPARATOR &&
                                        instruction->next->type == T_SPACE)
            pop_next(instruction);
        else
            break;
    }
    if (instruction->next != NULL)
        clear_next(instruction->next);
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
    clear_current(instruction);
    clear_next(instruction);
}
