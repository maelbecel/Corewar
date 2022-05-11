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

static void free_instruction(instruction_t *instruction)
{
    free(instruction->token);
    if (instruction->prev != NULL)
        free(instruction->prev);
    if (instruction->next != NULL)
        free_instruction(instruction->next);
    else
        free(instruction);
}

void free_instructions(instruction_t **instructions)
{
    if (instructions != NULL) {
        for (size_t i = 0; instructions[i] != NULL; i++)
            free_instruction(instructions[i]);
    }
    free(instructions);
}
