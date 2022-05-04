/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** assembler
*/

#include "my.h"
#include "printf.h"
#include "asm.h"

int assembler(char *file_name)
{
    FILE *file = NULL;

    file = fopen(file_name, "r");
    if (!file)
        return EXIT_ERROR;
    fclose(file);
    return EXIT_SUCCESS;
}
