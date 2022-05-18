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

    if (!header)
        return NULL;
    header->magic = htobe32(COREWAR_EXEC_MAGIC);
    if (!((*line) = get_clean_line(file_name)))
        return NULL;
    my_strcpy(header->prog_name, get_name(*line));
    free(*line);
    if (!((*line) = get_clean_line(file_name)))
        return NULL;
    my_strcpy(header->comment, get_comment(*line));
    free(*line);
    *line = NULL;
    return header;
}
