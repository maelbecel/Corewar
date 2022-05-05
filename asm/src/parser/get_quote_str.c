/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** return the string in double quote
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include "op.h"

static size_t count_occur(char *str, char c)
{
    size_t nbr_occur = 0;

    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            nbr_occur++;
    }
    return nbr_occur;
}

char *get_quote_str(char *line)
{
    int index = 0;
    size_t quote[2] = {0};

    if (count_occur(line, '\"') != 2)
        return NULL;
    for (size_t i = 0; line[i] != '\0'; i++) {
        if (line[i] == '\"') {
            quote[index] = i;
            index++;
        }
    }
    if (my_strlen(line + quote[1]) != 1)
        return NULL;
    line[quote[1]] = '\0';
    line += quote[0] + 1;
    return line;
}
