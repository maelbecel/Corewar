/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** realloc instructions array
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include "op.h"

const separator_t separator[] =
{
    {SEPARATOR_CHAR, D_SEPARATOR, T_SEPARATOR},
    {DIRECT_CHAR, D_GET, T_DIR},
    {LABEL_CHAR, D_GET, T_LABEL},
    {TAB, D_NORMAL, T_SPACE},
    {SPACE, D_NORMAL, T_SPACE},
    {0, T_OTHER, T_OTHER},
};

static int get_separator_type(char c)
{
    for (int pos = 0; separator[pos].token != 0; pos++) {
        if (separator[pos].token == c)
            return pos;
    }
    return -1;
}

static int add_special_token(int index, instruction_t *start,
                                                        instruction_t *last)
{
    instruction_t *data = NULL;
    char str[2] = {0};

    str[0] = separator[index].token;
    if (!my_strlen(last->str)) {
        last->str = my_charcat(last->str, separator[index].token);
        last->type = separator[index].type;
        last->attribut = separator[index].attribut;
    } else {
        data = create_instruction(str, separator[index].type,
                                                    separator[index].attribut);
        if (!data)
            return EXIT_ERROR;
        insert_new_instruction(start, data);
    }
    data = create_instruction(NULL, 0, 0);
    if (!data)
        return EXIT_ERROR;
    insert_new_instruction(start, data);
    return EXIT_SUCCESS;
}

static int parsing(instruction_t *start,  instruction_t *last, char *argv,
                                                                    size_t i)
{
    int separator_type = 0;

    separator_type = get_separator_type(argv[i]);
    if (separator_type == -1) {
        if (!(last->str = my_charcat(last->str, argv[i])))
            return EXIT_ERROR;
    } else {
        if (add_special_token(separator_type, start, last) == EXIT_ERROR)
            return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

instruction_t *parse_instruction(char *argv)
{
    instruction_t *start = init_instruction(argv);
    instruction_t *last = NULL;

    if (!start)
        return NULL;
    for (size_t i = 1; argv[i] != '\0'; i++) {
        last = go_to_last(start);
        if (parsing(start, last, argv, i) == EXIT_ERROR)
            return NULL;
    }
    return start;
}
