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
    int id_quotes = 0;
    size_t pos_quote[2] = {0};

    if (count_occur(line, QUOTES) != 2)
        return NULL;
    for (size_t i = 0; line[i] != '\0'; i++) {
        if (line[i] == QUOTES)
            pos_quote[id_quotes++] = i;
    }
    if (my_strlen(line + pos_quote[1]) != 1)
        return NULL;
    line[pos_quote[1]] = '\0';
    line += pos_quote[0] + 1;
    return line;
}
