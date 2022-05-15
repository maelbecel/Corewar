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
    unsigned char count = 0;
    int shift = 6;

    for (instruction_t *tmp = instruction; tmp != NULL; tmp = tmp->next) {
        if (tmp->attribut == D_REG) {
            count += (1 << shift);
            shift -= 2;
            continue;
        }
        if (tmp->attribut == D_IND) {
            count += (3 << shift);
            shift -= 2;
            continue;
        }
        if (tmp->attribut == D_DIR) {
            count += (2 << shift);
            shift -= 2;
            continue;
        }
    }
    fwrite(&count, 1, sizeof(char), file);
}
