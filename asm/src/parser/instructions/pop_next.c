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

int pop_next(instruction_t *instruction)
{
    instruction_t *pop = instruction->next;
    instruction_t *new = NULL;

    if (!pop)
        return EXIT_ERROR;
    if (pop->next != NULL) {
        new = pop->next;
        new->prev = instruction;
    }
    free(pop->str);
    free(pop);
    instruction->next = new;
    return EXIT_SUCCESS;
}
