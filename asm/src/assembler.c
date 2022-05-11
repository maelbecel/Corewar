/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** assembler
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include "op.h"

int assembler(char *file_name)
{
    FILE *file = NULL;
    header_t *header = NULL;
    char *line = "";
    instruction_t **instructions = NULL;

    file = fopen(file_name, "r");
    if (!file)
        return EXIT_ERROR;
    if (!(header = get_header(file, &line)))
        return EXIT_ERROR;
    if (!line)
        line = get_clean_line(file);
    instructions = get_instructions(file, line);
    get_champion_size(header, instructions);
    fclose(file);
    free(header);
    free_instructions(instructions);
    return EXIT_SUCCESS;
}
