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

static int error_register(instruction_t *token)
{
    int registre = 0;

    token->type = D_REG;
    registre = my_getnbr(token->str+1);
    if (registre < 1 || registre > REG_NUMBER)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static int error_direct(instruction_t *token)
{
    instruction_t *tmp = token;

    if (tmp == NULL)
        return EXIT_ERROR;
    if (tmp->id == ID_LABEL) {
        tmp = tmp->next;
        if (tmp == NULL || tmp->id != ID_WIHOUT)
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

static int error_indirect(instruction_t *token)
{
    instruction_t *tmp = token;

    if (tmp->id == ID_LABEL) {
        tmp = tmp->next;
        if (tmp == NULL || tmp->id != ID_WIHOUT)
            return EXIT_ERROR;
        tmp->type = D_IND;
        if (char_list_in_str(tmp->str, LABEL_CHARS))
            return EXIT_ERROR;
    } else {
        if (char_list_in_str(token->str, "0123456789-"))
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

int error_params(instruction_t *token)
{
    int status = EXIT_SUCCESS;
    instruction_t *tmp = token;

    if (error_one_params(tmp) == EXIT_ERROR)
        return EXIT_ERROR;
    while (tmp->type < D_REG)
        tmp = tmp->next;
    if (tmp->next != NULL) {
        if (tmp->next->id == ID_SEPARATOR && tmp->next->next != NULL)
            status = error_params(tmp->next->next);
        else
            return EXIT_ERROR;
    }
    return status;
}