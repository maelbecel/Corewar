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

static short get_params_size_short(ATTRIBUT attribut, bool index_params)
{
    if (attribut == D_REG)
        return 1;
    if ((attribut == D_DIR || attribut == D_IND) && index_params)
        return 2;
    if (attribut == D_DIR)
        return DIR_SIZE;
    if (attribut == D_IND)
        return IND_SIZE;
    return 0;
}

short compute_size_short(instruction_t *tmp)
{
    short size = 1;
    int index = 0;
    bool index_params;

    index = get_op(tmp->str);
    if (op_tab[index].nbr_args != 1 || op_tab[index].code == 16)
        size++;
    index_params = is_index_type(tmp->str);
    while (tmp != NULL) {
        if (tmp->attribut >= D_REG)
            size += get_params_size_short(tmp->attribut, index_params);
        tmp = tmp->next;
    }
    return size;
}

unsigned short get_adress_label_short(char *label,
                                    instruction_t **instructions, int index)
{
    unsigned short adress = 0;

    for (size_t pos = index; instructions[pos] != NULL; pos++) {
        if (instructions[pos]->next->type == T_LABEL &&
                            my_strcmp(instructions[pos]->str, label) == 0)
            return adress;
        adress += get_instruction_size(instructions[pos], true);
    }
    adress = 65535;
    for (ssize_t pos = index - 1; pos >= 0; pos--) {
        if (instructions[pos]->next->type == T_LABEL &&
                            my_strcmp(instructions[pos]->str, label) == 0) {
            adress -= get_instruction_size(instructions[pos], true);
            return adress + 1;
        }
        adress -= get_instruction_size(instructions[pos], true);
    }
    return 0;
}

unsigned int get_adress_label(char *label, instruction_t **instructions,
                                                                    int index)
{
    unsigned int adress = 0;

    for (size_t pos = index; instructions[pos] != NULL; pos++) {
        if (instructions[pos]->next->type == T_LABEL &&
                                my_strcmp(instructions[pos]->str, label) == 0)
            return adress;
        adress += get_instruction_size(instructions[pos], false);
    }
    adress = 4294967295;
    for (ssize_t pos = index - 1; pos >= 0; pos--) {
        if (instructions[pos]->next->type == T_LABEL &&
                            my_strcmp(instructions[pos]->str, label) == 0) {
            adress -= get_instruction_size(instructions[pos], false);
            return adress + 1;
        }
        adress -= get_instruction_size(instructions[pos], false);
    }
    return 0;
}
