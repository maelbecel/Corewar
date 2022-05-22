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

static int get_type(ATTRIBUT attribut)
{
    if (attribut == A_REG)
        return T_REG;
    if (attribut == A_DIR)
        return T_DIR;
    if (attribut == A_IND)
        return T_IND;
    return 0;
}

static int check_type(instruction_t *move, op_t op, size_t *arg)
{
    if (move->attribut > A_SEPARATOR) {
        if ((get_type(move->attribut) & op.attribut[(*arg)]) == 0)
            return EXIT_ERROR;
        (*arg)++;
    }
    return EXIT_SUCCESS;
}

static bool check_args(op_t op, instruction_t *instruction)
{
    size_t arg = 0;
    instruction_t *move = instruction;

    for (size_t i = 0; move; i++) {
        if (check_type(move, op, &arg) == EXIT_ERROR)
            return false;
        move = move->next;
    }
    return true;
}

static char get_argc(instruction_t *instruction)
{
    size_t nb = 0;
    instruction_t *move = instruction;

    for (size_t i = 0; move; i++) {
        if (move->attribut >= A_REG)
            nb++;
        move = move->next;
    }
    return nb;
}

bool check_instruction(instruction_t *instruction)
{
    int pos = 0;

    if (!instruction->next->next)
        return true;
    if (instruction->next->type == T_LABEL)
        pos = get_op(instruction->next->next->next->str);
    else
        pos = get_op(instruction->str);
    if (op_tab[pos].nbr_args != get_argc(instruction))
        return false;
    if (!check_args(op_tab[pos], instruction))
        return false;
    return true;
}
