/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** return name and comment of .s
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include "op.h"

header_t *get_header(FILE *file_name, char **line)
{
    header_t *header = malloc(sizeof(header_t));

    if (!((*line) = get_line(file_name)))
        return NULL;
    if (my_strcpy(header->prog_name, get_name(*line)) == NULL) {
        free(*line);
        return NULL;
    }
    free(*line);
    if (!((*line) = get_line(file_name)))
        return NULL;
    if (my_strcpy(header->comment, get_comment(*line)) == NULL)
        return NULL;
    free(*line);
    *line = NULL;
    return header;
}
