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
    int byteshift = 6;

    for (instruction_t *tmp = instruction; tmp != NULL; tmp = tmp->next) {
        // printf("tmp->str = %s\n", tmp->str);
        if (tmp->attribut == A_REG) {
            count += (1 << byteshift);
            byteshift -= 2;
        }
        if (tmp->attribut == A_DIR) {
            count += (2 << byteshift);
            byteshift -= 2;
        }
        if (tmp->attribut == A_IND) {
            count += (3 << byteshift);
            byteshift -= 2;
        }
    }
    printf("write_codebytes: count = %d\n", count) ;
    fwrite(&count, 1, sizeof(char), file);
}
