/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** write .s in bytes
*/

#include "writer.h"
#include "my.h"

unsigned int write_code(header_t *header, UNUSED instruction_t **instructions)
{
    char *filename = my_strdup(header->prog_name);
    FILE *file = NULL;

    filename = concatener(filename, EXTENTION);

    if (!filename)
        return EXIT_ERROR;

    file = fopen(filename, "w");

    if (!file)
        return EXIT_ERROR;

    write_header(header, filename, file);
    write_instructions(instructions, file);
    return EXIT_SUCCESS;
}
