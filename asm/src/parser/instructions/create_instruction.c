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
    instruction->str = malloc(sizeof(char) * 1);
    if (!instruction->str) {
        free(instruction);
        return NULL;
    }
    if (str != NULL) {
        if (!(instruction->str = my_strdup(str)))
            return NULL;
    } else
        instruction->str[0] = '\0';
    instruction->id = id;
    instruction->type = type;
    instruction->next = NULL;
    instruction->prev = NULL;
    return instruction;
}
