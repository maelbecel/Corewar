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

const char *cmd[] = {
    "lfork",
    "sti",
    "fork",
    "ldi",
    "lldi",
    "zjmp",
    NULL,
};

static int get_params_size(TYPE type, bool index_params)
{
    if (type == D_REG)
        return 1;
    if ((type == D_DIR || type == D_IND) && index_params)
        return 2;
    if (type == D_DIR)
        return DIR_SIZE;
    if (type == D_IND)
        return IND_SIZE;
    return 0;
}

bool is_index_type(char *str)
{
    for (size_t i = 0; cmd[i] != NULL; i++) {
        if (my_strcmp(str, cmd[i]) == 0)
            return true;
    }
    return false;
}

static int compute_size(instruction_t *tmp)
{
    int size = 1;
    int index = 0;
    bool index_params;

    index = get_op(tmp->str);
    if (op_tab[index].nbr_args != 1 || op_tab[index].code == 16)
        size++;
    index_params = is_index_type(tmp->str);
    while (tmp != NULL) {
        if (tmp->type >= D_REG)
            size += get_params_size(tmp->type, index_params);
        tmp = tmp->next;
    }
    return size;
}

static int get_line_size(instruction_t *instruction)
{
    instruction_t *tmp = instruction;

    if (tmp->next->is == IS_LABEL) {
        tmp = tmp->next;
        if (tmp->next != NULL)
            tmp = tmp->next->next;
        else
            return 0;
    }
    return compute_size(tmp);
}

void get_champion_size(header_t *header, instruction_t **instructions)
{
    for (size_t i = 0; instructions[i] != NULL; i++) {
        header->prog_size += get_line_size(instructions[i]);
    }
    header->prog_size = htobe32(header->prog_size);
}
