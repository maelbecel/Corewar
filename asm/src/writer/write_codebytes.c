/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** function to write the codebytes of the registre
*/

#include "my.h"
#include "asm.h"
#include "op.h"

void write_codebytes(instruction_t *instruction, FILE *file)
{
    unsigned int count = 0;

    while (instruction) {
        if (instruction->attribut == D_REG) {
            count += 1;
            count *= 100;
        }
        if (instruction->attribut == D_DIR) {
            count += 10;
            count *= 100;
        }
        if (instruction->attribut == D_IND) {
            count += 11;
            count *= 100;
        }
        instruction = instruction->next;
    }
    fwrite(&count, 1, sizeof(int), file);
}
