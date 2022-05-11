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

static int error_register(instruction_t *instruction)
{
    int nbr_reg = 0;

    instruction->type = D_REG;
    nbr_reg = my_getnbr(instruction->str + 1);
    if (nbr_reg < 1 || nbr_reg > REG_NUMBER)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static int error_direct(instruction_t *instruction)
{
    instruction_t *tmp = instruction;

    if (!tmp)
        return EXIT_ERROR;
    if (tmp->id == ID_LABEL) {
        tmp = tmp->next;
        if (!tmp || tmp->id != ID_WIHOUT)
            return EXIT_ERROR;
        tmp->type = D_DIR;
        if (char_list_in_str(tmp->str, LABEL_CHARS))
            return EXIT_ERROR;
    } else {
        tmp->type = D_DIR;
        if (tmp->id != ID_WIHOUT || char_list_in_str(tmp->str, "0123456789-"))
            return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

static int error_indirect(instruction_t *instruction)
{
    instruction_t *tmp = instruction;

    if (tmp->id == ID_LABEL) {
        tmp = tmp->next;
        if (!tmp || tmp->id != ID_WIHOUT)
            return EXIT_ERROR;
        tmp->type = D_IND;
        if (char_list_in_str(tmp->str, LABEL_CHARS))
            return EXIT_ERROR;
    } else {
        if (char_list_in_str(instruction->str, "0123456789-"))
            return EXIT_ERROR;
        tmp->type = D_IND;
    }
    return EXIT_SUCCESS;
}

static int error_one_params(instruction_t *tmp)
{
    if (tmp->str[0] == 'r') {
        if (error_register(tmp) == EXIT_ERROR)
            return EXIT_ERROR;
    } else if (tmp->id == ID_DIR) {
        if (error_direct(tmp->next) == EXIT_ERROR)
            return EXIT_ERROR;
    } else {
        if (error_indirect(tmp) == EXIT_ERROR)
            return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

int error_params(instruction_t *instruction)
{
    int exit_code = EXIT_SUCCESS;
    instruction_t *tmp = instruction;

    if (error_one_params(tmp) == EXIT_ERROR)
        return EXIT_ERROR;
    while (tmp->type < D_REG)
        tmp = tmp->next;
    if (tmp->next != NULL) {
        if (tmp->next->id == ID_SEPARATOR && tmp->next->next != NULL)
            exit_code = error_params(tmp->next->next);
        else
            return EXIT_ERROR;
    }
    return exit_code;
}
