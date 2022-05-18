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

int get_op(char *str)
{
    for (size_t pos = 0; op_tab[pos].mnemonique != NULL; pos++) {
        if (my_strcmp(str, op_tab[pos].mnemonique) == 0)
            return pos;
    }
    return -1;
}

static instruction_t *check_label(instruction_t *tmp)
{
    if (!tmp->next)
        return NULL;
    if (tmp->next->type == T_LABEL) {
        if (char_list_in_str(tmp->str, LABEL_CHARS) == false)
            return NULL;
        if (!tmp->next->next)
            return tmp->next;
        tmp = tmp->next->next;
        if (tmp->type != T_SPACE)
            return NULL;
        tmp = tmp->next;
    }
    if (!tmp)
        return NULL;
    return tmp;
}

int check_error_instruction(instruction_t *instruction)
{
    int index = 0;
    instruction_t *tmp = instruction;

    tmp = check_label(tmp);
    if (!tmp)
        return EXIT_ERROR;
    if (tmp->type == T_LABEL)
        return EXIT_SUCCESS;
    index = get_op(tmp->str);
    if (index == -1)
        return EXIT_ERROR;
    tmp = tmp->next;
    if (!tmp || (tmp->type != T_SPACE && tmp->type != T_SEPARATOR))
        return EXIT_ERROR;
    tmp = tmp->next;
    if (!tmp)
        return EXIT_ERROR;
    return error_params(tmp);
}
