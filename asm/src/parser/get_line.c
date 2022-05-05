/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** recode getline
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include "op.h"

static void remove_comment(char *line)
{
    for (size_t pos = 0; line[pos] != '\0'; pos++) {
        if (line[pos] == COMMENT_CHAR) {
            line[pos] = '\0';
            return;
        }
    }
}

static char *return_str(char *line, size_t shift)
{
    char *str = my_strdup(line+shift);

    free(line);
    return str;
}

char *clean_line(char *line)
{
    size_t shift = 0;

    remove_comment(line);
    for (size_t pos = 0; line[pos] != '\0'; pos++) {
        if (line[pos] == ' ' || line[pos] == '\t') {
            shift++;
        } else {
            break;
        }
    }
    if (!my_strlen(line))
        return line;
    for (size_t pos = my_strlen(line) - 1; pos > 0; pos--) {
        if (line[pos] == ' ' || line[pos] == '\t') {
            line[pos] = '\0';
        } else {
            break;
        }
    }
    return return_str(line, shift);
}

char *get_line(FILE *file_name)
{
    char *line = NULL;
    ssize_t nread = 0;
    size_t len = 0;

    while (true) {
        nread = getline(&line, &len, file_name);
        if (nread == -1)
            return NULL;
        if (line[nread - 1] == '\n')
            line[nread - 1] = '\0';
        line = clean_line(line);
        if (my_strlen(line))
            break;
        free(line);
        line = NULL;
        len = 0;
    }
    return line;
}