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

static size_t do_shift(char *line)
{
    size_t shift = 0;

    for (size_t pos = 0; line[pos] != '\0'; pos++) {
        if (line[pos] == SPACE || line[pos] == TAB)
            shift++;
        else
            break;
    }
    return shift;
}

static void clean_line(char *line)
{
    for (size_t pos = my_strlen(line) - 1; pos > 0; pos--) {
        if (line[pos] == SPACE || line[pos] == TAB)
            line[pos] = '\0';
        else
            break;
    }
}

static char *clean_str(char *line)
{
    size_t shift = 0;
    char *str = NULL;

    if (!line)
        return NULL;
    remove_comment(line);
    shift = do_shift(line);
    if (!my_strlen(line))
        return line;
    clean_line(line);
    str = my_strdup(line + shift);
    free(line);
    return str;
}

char *get_clean_line(FILE *file_name)
{
    char *line = NULL;
    ssize_t get = 0;
    size_t len = 0;

    while (true) {
        if ((get = getline(&line, &len, file_name)) == -1)
            return NULL;
        if (line[get - 1] == '\n')
            line[get - 1] = '\0';
        line = clean_str(line);
        if (my_strlen(line) != 0)
            break;
        free(line);
        line = NULL;
        len = 0;
    }
    return line;
}
