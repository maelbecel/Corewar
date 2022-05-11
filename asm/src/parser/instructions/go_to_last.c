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

instruction_t *go_to_last(instruction_t *start)
{
    instruction_t *last_token = start;

    if (!start)
        return NULL;
    if (start->next != NULL)
        last_token = go_to_last(start->next);
    return last_token;
}
