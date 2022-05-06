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

    file = fopen(file_name, "r");
    if (!file)
        return EXIT_ERROR;
    if ((header = get_header(file, &line)) == NULL)
        return EXIT_ERROR;
    my_printf("name: %s | comment: %s\n", header->prog_name, header->comment);
    fclose(file);
    free(header);
    return EXIT_SUCCESS;
}
