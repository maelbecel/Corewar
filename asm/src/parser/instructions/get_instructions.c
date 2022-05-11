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

instruction_t **get_instructions(FILE *source_file, char *line)
{
    instruction_t **instruction_line = malloc(sizeof(instruction_t *) * 2);

    size_t array = 2;

    if (!instruction_line)
        return NULL;
    instruction_line[0] = NULL;
    instruction_line[1] = NULL;
    my_printf("line: %s\n", line);
    for (size_t i = 0; line != NULL; i++) {
        instruction_line[i] = tokeniser(line);
        clean_instructions(instruction_line[i]);
        if (!instruction_line[i] ||
            error_syntax_line(instruction_line[i]) ||
            !check_instruction(instruction_line[i])) {
            free(line);
            free_instructions(instruction_line);
            return NULL;
        }
        array++;
        instruction_line = realloc_instructions(instruction_line, array);
        if (instruction_line == NULL)
            return NULL;
        free(line);
        line = get_clean_line(source_file);
    }
    free(line);
    if (instruction_line == NULL || error_label(instruction_line)) {
        free_instructions(instruction_line);
        return NULL;
    }
    return instruction_line;
}
