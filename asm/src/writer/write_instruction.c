/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** write instruction function in byte
*/

#include "writer.h"

static void write_codebyte_parameters(instruction_t *instruction, int index,
FILE *file)
{
    if (op_tab[index].code == 16 || op_tab[index].nbr_args != 1) {
        write_codebytes(instruction, file);
    }
    return;
}

unsigned int write_instruction(instruction_t *instruction,
char *filename, FILE *file)
{
    instruction_t *instruction_tmp = instruction;
    int index = get_op(instruction_tmp->str);
    size_t err = 0;

    if (index == -1) {
        if (instruction->next->next == NULL) {
            printf("NULL\n");
            return;
        }
        printf("Look forward\n");
        instruction_tmp = instruction_tmp->next->next->next;
        index = get_op(instruction_tmp->str);
    }

    err = fwrite(&(op_tab[index].code), 1, sizeof(char), file);
    if (err != sizeof(unsigned char)) {
        my_printf("failed to write instruction\n");
        return 84;
    }
    write_codebyte_parameters(instruction_tmp, index, file);
    return index;
}
