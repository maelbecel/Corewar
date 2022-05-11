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

const parser_t delimit[] =
{
    {' ', D_NORMAL, ID_SPACE},
    {'\t', D_NORMAL, ID_SPACE},
    {DIRECT_CHAR, D_GET, ID_DIR},
    {LABEL_CHAR, D_GET, ID_LABEL},
    {SEPARATOR_CHAR, D_SEPARATOR, ID_SEPARATOR},
    {0, ID_WIHOUT, ID_WIHOUT},
};

static char *add_one_char(char *str, char c)
{
    int size = my_strlen(str);
    char *new_str = malloc(sizeof(char) * (size + 2));

    if (new_str == NULL)
        return NULL;
    my_strcpy(new_str, str);
    free(str);
    new_str[size] = c;
    new_str[size + 1] = '\0';
    return new_str;
}

static int is_special_id(char c)
{
    for (int i = 0; delimit[i].token != 0; i++) {
        if (delimit[i].token == c) {
            return i;
        }
    }
    return -1;
}

static instruction_t *init_node(char *av)
{
    instruction_t *start = NULL;
    char str[2] = {0};

    str[0] = av[0];
    start = create_instruction(str, ID_WIHOUT, D_NORMAL);
    return start;
}

static int add_special_token(int index, instruction_t *start, instruction_t *last)
{
    instruction_t *data = NULL;
    char str[2] = {0};

    str[0] = delimit[index].token;
    if (!my_strlen(last->token)) {
        last->token = add_one_char(last->token, delimit[index].token);
        last->id = delimit[index].id;
        last->type = delimit[index].type;
    } else {
        data = create_instruction(str, delimit[index].id, delimit[index].type);
        if (data == NULL)
            return EXIT_ERROR;
        add_node_at_the_end(start, data);
    }
    data = create_instruction(NULL, 0, 0);
    if (data == NULL)
        return EXIT_ERROR;
    add_node_at_the_end(start, data);
    return EXIT_SUCCESS;
}

instruction_t *tokeniser(char *av)
{
    int index = 0;
    instruction_t *start = init_node(av);
    instruction_t *last = NULL;

    if (start == NULL)
        return NULL;
    for (size_t i = 1; av[i] != '\0'; i++) {
        index = is_special_id(av[i]);
        last = get_last_token(start);
        if (index == -1) {
            last->token = add_one_char(last->token, av[i]);
            if (last->token == NULL)
                return NULL;
        } else {
            if (add_special_token(index, start, last) == EXIT_ERROR)
                return NULL;
        }
    }
    return start;
}