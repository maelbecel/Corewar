/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** return name and comment of .s
*/

#include "my.h"
#include "corewar.h"
#include "printf.h"
#include "asm.h"
#include "op.h"

header_t *get_header(FILE *file_name, char **line)
{
    header_t *header = my_calloc(sizeof(header_t));
    char *comment = NULL;
    char *name = NULL;

    if (!header)
        return NULL;
    header->magic = htobe32(COREWAR_EXEC_MAGIC);
    if (!((*line) = get_clean_line(file_name)) || !(name = get_name(*line)))
        return NULL;
    my_strcpy(header->prog_name, name);
    free(*line);
    if (!((*line) = get_clean_line(file_name)) ||
                                            !(comment = get_comment(*line)))
        return NULL;
    my_strcpy(header->comment, comment);
    free(*line);
    *line = NULL;
    return header;
}
