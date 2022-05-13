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

    if (instruction->prev->type == T_LABEL) {
        count = get_adress_label_short(instruction->str, instructions, index);
    } else {
        count = my_getnbr(instruction->str);
    }
    count = htobe16(count);
    fwrite(&count, 1, sizeof(short), file);
    return;
}

static void write_direct(int index, instruction_t *instruction,
    FILE *file, instruction_t **instructions, int mnemonique)
{
    unsigned int count = 0;

    if (is_index_type(op_tab[mnemonique].mnemonique) == true) {
        write_indirect(index, instruction, file, instructions);
        return;
    }
    if (instruction->prev->type == T_LABEL) {
        count = get_adress_label(instruction->str, instructions, index);
    } else {
        count = my_getnbr(instruction->str);
    }
    count = htobe32(count);
    fwrite(&count, 1, sizeof(int), file);
    return;
}

static void test_write(instruction_t *instruction, int index,
    FILE *file, instruction_t **instructions, int mnemonique)
{
    unsigned char count = 0;

    while (instruction) {
        if (instruction->attribut == D_REG) {
            count = my_getnbr(instruction->str);
            printf("count = %d\n", count);
            fwrite(&count, 1, sizeof(char), file);
        }
        if (instruction->attribut == D_IND) {
            write_indirect(index, instruction, file, instructions);
        }
        if (instruction->attribut == D_DIR) {
            write_direct(index, instruction, file, instructions, mnemonique);
        }
        instruction = instruction->next;
    }
}

unsigned int write_instructions(instruction_t **instructions,
    char *filename, FILE *file)
{
    int index = 0;

    for (size_t i = 0; instructions[i]; i++) {
        printf("Name: %s\n", instructions[i]->str);
        index = write_instruction(instructions[i], filename, file);
        test_write(instructions[i], i, file, instructions, index);
    }
    return 0;
}
