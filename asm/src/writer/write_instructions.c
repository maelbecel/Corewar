/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** write int in byte
*/

#include <stdio.h>
#include "writer.h"
#include "my.h"

static void write_indirect(int index, instruction_t *instruction,
                                    FILE *file, instruction_t **instructions)
{
    unsigned short count = 0;

    if (instruction->prev->type == T_LABEL)
        count = get_label_adress_short(instruction->str, instructions, index);
    else
        count = my_getnbr(instruction->str);
    count = htobe16(count);
    fwrite(&count, 1, sizeof(short), file);
    return;
}

static void write_direct(int index, instruction_t *instruction,
                    writer_t write, instruction_t **instructions)
{
    unsigned int count = 0;

    if (is_index_type(op_tab[write.mnemonique].mnemonique) == true)
        return write_indirect(index, instruction, write.file, instructions);
    if (instruction->prev->type == T_LABEL)
        count = get_label_adress(instruction->str, instructions, index);
    else
        count = my_getnbr(instruction->str);
    count = htobe32(count);
    fwrite(&count, 1, sizeof(int), write.file);
    return;
}

static void write_args(instruction_t *instruction, int index,
                    instruction_t **instructions, writer_t write)
{
    unsigned char count = 0;

    while (instruction) {
        if (instruction->attribut == A_REG) {
            count = my_getnbr(instruction->str);
            fwrite(&count, 1, sizeof(char), write.file);
        }
        if (instruction->attribut == A_IND)
            write_indirect(index, instruction, write.file, instructions);
        if (instruction->attribut == A_DIR)
            write_direct(index, instruction, write, instructions);
        instruction = instruction->next;
    }
}

unsigned int write_instructions(instruction_t **instructions, FILE *file)
{
    writer_t write;

    write.file = file;
    write.mnemonique = 0;

    for (size_t i = 0; instructions[i]; i++) {
        write.mnemonique = write_instruction(instructions[i], file);
        write_args(instructions[i], i, instructions, write);
    }
    return 0;
}
