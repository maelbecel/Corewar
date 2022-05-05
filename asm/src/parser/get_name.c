/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** return name of .s
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include "op.h"

char *get_name(char *line)
{
    char *str = NULL;

    if (my_strncmp(line, NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)))
        return NULL;
    line += my_strlen(NAME_CMD_STRING) + 1;
    str = get_quote_str(line);
    if (!str || my_strlen(str) > PROG_NAME_LENGTH)
        return NULL;
    return str;
}
