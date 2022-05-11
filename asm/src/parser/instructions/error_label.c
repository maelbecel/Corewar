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

static char **get_list_label(instruction_t **array)
{
    size_t index = 0;
    char **list = malloc(sizeof(char *) * 2);

    if (list == NULL)
        return NULL;
    list[0] = NULL;
    list[1] = NULL;
    for (size_t i = 0; array[i] != NULL; i++) {
        if (array[i]->next->id == ID_LABEL) {
            list[index] = my_strdup(array[i]->str);
            if (list[index] == NULL)
                return NULL;
            list = my_array_realloc(list);
            index++;
        }
    }
    return list;
}

static bool find_label_on_list(char **list, char *label)
{
    for (size_t i = 0; list[i] != NULL; i++) {
        if (!my_strcmp(label, list[i]))
            return true;
    }
    return false;
}

static bool check_label(instruction_t *token, char **list)
{
    for (instruction_t *tmp = token; tmp != NULL; tmp = tmp->next) {
        if (tmp->type > D_REG && tmp->prev->id == ID_LABEL &&
            !find_label_on_list(list, tmp->str)) {
            return false;
        }
    }
    return true;
}

static bool double_label_declaration(char **list)
{
    size_t nb_label = 0;

    for (size_t i = 0; list[i] != NULL; i++) {
        nb_label = 0;
        for (size_t j = 0; list[j] != NULL; j++) {
            if (!my_strcmp(list[i], list[j]))
                nb_label++;
        }
        if (nb_label != 1)
            return true;
    }
    return false;
}

bool error_label(instruction_t **array)
{
    char **list = get_list_label(array);

    if (list == NULL)
        return true;
    for (size_t i = 0; array[i] != NULL; i++) {
        if (!check_label(array[i], list)) {
            my_free_2d_array(list);
            return true;
        }
    }
    if (double_label_declaration(list)) {
        my_free_2d_array(list);
        return true;
    }
    my_free_2d_array(list);
    return false;
}