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

void *get_params_size(ATTRIBUT attribut, bool index_params)
{
    if (attribut == D_REG)
        return (void *)1;
    if ((attribut == D_DIR || attribut == D_IND) && index_params)
        return (void *)2;
    if (attribut == D_DIR)
        return (void *)DIR_SIZE;
    if (attribut == D_IND)
        return (void *)IND_SIZE;
    return 0;
}

bool is_index_type(char *str)
{
    for (size_t pos = 0; cmd[pos] != NULL; pos++) {
        if (my_strcmp(str, cmd[pos]) == 0)
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
        if (tmp->attribut >= D_REG)
            size += (int)get_params_size(tmp->attribut, index_params);
        tmp = tmp->next;
    }
    return size;
}

int get_instruction_size(instruction_t *instruction, bool is_short)
{
    instruction_t *tmp = instruction;

    if (tmp->next->type == T_LABEL) {
        tmp = tmp->next;
        if (!tmp->next)
            return 0;
        else
            tmp = tmp->next->next;
    }
    if (!is_short)
        return compute_size(tmp);
    else
        return compute_size_short(tmp);
}

void get_champion_size(header_t *header, instruction_t **instructions)
{
    for (size_t pos = 0; instructions[pos] != NULL; pos++)
        header->prog_size += get_instruction_size(instructions[pos], false);
    header->prog_size = htobe32(header->prog_size);
}
