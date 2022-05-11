/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** return comment of .s
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include "op.h"

char *get_comment(char *line)
{
    char *str = NULL;

    if (my_strncmp(line, COMMENT_CMD_STRING,
                                        my_strlen(COMMENT_CMD_STRING)) != 0)
        return NULL;
    line += my_strlen(COMMENT_CMD_STRING) + 1;
    str = get_quote_str(line);
    if (!str || my_strlen(str) > COMMENT_LENGTH)
        return NULL;
    return str;
}
