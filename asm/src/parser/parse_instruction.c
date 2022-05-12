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

const is_t delimit[] =
{
    {' ', D_NORMAL, T_SPACE},
    {'\t', D_NORMAL, T_SPACE},
    {DIRECT_CHAR, D_GET, T_DIR},
    {LABEL_CHAR, D_GET, T_LABEL},
    {SEPARATOR_CHAR, D_SEPARATOR, T_SEPARATOR},
    {0, T_OTHER, T_OTHER},
};

static int is_special_id(char c)
{
    for (int pos = 0; delimit[pos].token != 0; pos++) {
        if (delimit[pos].token == c)
            return pos;
    }
    return -1;
}

static instruction_t *init_node(char *av)
{
    instruction_t *start = NULL;
    char str[2] = {0};

    str[0] = av[0];
    start = create_instruction(str, T_OTHER, D_NORMAL);
    return start;
}

static int add_special_token(int index, instruction_t *start, instruction_t *last)
{
    instruction_t *data = NULL;
    char str[2] = {0};

    str[0] = delimit[index].token;
    if (!my_strlen(last->str)) {
        last->str = my_charcat(last->str, delimit[index].token);
        last->type = delimit[index].type;
        last->attribut = delimit[index].attribut;
    } else {
        data = create_instruction(str, delimit[index].type, delimit[index].attribut);
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

instruction_t *parse_instruction(char *av)
{
    int index = 0;
    instruction_t *start = init_node(av);
    instruction_t *last = NULL;

    if (!start)
        return NULL;
    for (size_t i = 1; av[i] != '\0'; i++) {
        index = is_special_id(av[i]);
        last = go_to_last(start);
        if (index == -1) {
            last->str = my_charcat(last->str, av[i]);
            if (!last->str)
                return NULL;
        } else {
            if (add_special_token(index, start, last) == EXIT_ERROR)
                return NULL;
        }
    }
    return start;
}
