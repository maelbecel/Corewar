/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** write .s in bytes
*/

#include "writer.h"
#include "my.h"

static char *remove_extension(char *filename)
{
    for (size_t pos = my_strlen(filename) - 1; pos > 1; pos--) {
        if (filename[pos] == '.') {
            filename[pos] = '\0';
            break;
        }
        filename[pos] = '\0';
    }
    return filename;
}

unsigned int write_code(header_t *header, instruction_t **instructions,
                                                        char *filename_origin)
{
    char *filename = remove_extension(my_strdup(filename_origin));
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
