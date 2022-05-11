/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** return a instruction struct filled
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include "op.h"

instruction_t *create_instruction(char *str, ID id, TYPE type)
{
    instruction_t *instruction = malloc(sizeof(instruction_t));

    if (!instruction)
        return NULL;
    if (!str) {
        instruction->token = malloc(sizeof(char) * 1);
        if (!instruction->token)
            return NULL;
        instruction->token[0] = '\0';
    } else
        if (!(instruction->token = my_strdup(str)))
            return NULL;
    instruction->id = id;
    instruction->type = type;
    instruction->next = NULL;
    instruction->prev = NULL;
    return instruction;
}
