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

static unsigned int check(instruction_t **array, char ***list_label,
                                        size_t pos, size_t *pos_list)
{
    if (array[pos]->next->type == T_LABEL) {
        if (!((*list_label)[(*pos_list)] = my_strdup(array[pos]->str)))
            return EXIT_ERROR;
        (*list_label) = my_array_realloc((*list_label));
        (*pos_list)++;
    }
    return EXIT_SUCCESS;
}

static char **create_label_list(instruction_t **array)
{
    static int zzz = 0;
    size_t pos_list = 0;
    char **list_label = malloc(sizeof(char *) * 2);

    zzz++;
    if (!list_label)
        return NULL;
    list_label[0] = NULL;
    list_label[1] = NULL;
    for (size_t pos = 0; array[pos] != NULL; pos++) {
        if (check(array, &list_label, pos, &pos_list) == EXIT_ERROR)
            return NULL;
    }
    return list_label;
}

static bool find_label_on_list(char **list_label, char *label)
{
    for (size_t pos = 0; list_label[pos] != NULL; pos++) {
        if (my_strcmp(label, list_label[pos]) == 0) {
            return true;
        }
    }
    return false;
}

static bool check_label(instruction_t *instruction, char **list_label)
{
    for (instruction_t *tmp = instruction; tmp != NULL; tmp = tmp->next) {
        if (tmp->attribut > A_REG && tmp->prev->type == T_LABEL &&
            find_label_on_list(list_label, tmp->str) == false) {
            return true;
        }
    }
    return false;
}

bool check_error_label(instruction_t **instructions)
{
    char **list_label = create_label_list(instructions);

    if (!list_label)
        return true;
    for (size_t pos = 0; instructions[pos] != NULL; pos++) {
        if (check_label(instructions[pos], list_label) == true) {
            my_free_2d_array(list_label);
            return true;
        }
    }
    if (count_nbr_label(list_label) == true) {
        my_free_2d_array(list_label);
        return true;
    }
    my_free_2d_array(list_label);
    return false;
}
