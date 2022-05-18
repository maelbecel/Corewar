/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** return instructions array
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include "op.h"

static instruction_t **interprate_file(instruction_t **instruction_line,
                                            FILE *source_file, char *line)
{
    size_t array = 2;

    for (size_t i = 0; line != NULL; i++) {
        instruction_line[i] = parse_instruction(line);
        clean_instruction(instruction_line[i]);
        if (!instruction_line[i] ||
            check_error_instruction(instruction_line[i]) != 0 ||
            !check_instruction(instruction_line[i])) {
            free(line);
            free_instructions(instruction_line);
            return NULL;
        }
        array++;
        instruction_line = realloc_instructions(instruction_line, array);
        if (!instruction_line)
            return NULL;
        free(line);
        line = get_clean_line(source_file);
    }
    return instruction_line;
}

instruction_t **get_instructions(FILE *source_file, char *line)
{
    instruction_t **instruction_line = malloc(sizeof(instruction_t *) * 2);

    if (!instruction_line)
        return NULL;
    instruction_line[0] = NULL;
    instruction_line[1] = NULL;
    if (!(instruction_line =
                interprate_file(instruction_line, source_file, line)) ||
                                        check_error_label(instruction_line)) {
        free_instructions(instruction_line);
        return NULL;
    }
    return instruction_line;
}
