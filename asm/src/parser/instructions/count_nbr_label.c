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

static void check(char **list_label, size_t pos, size_t *count)
{
    for (size_t pos_cmp = 0; list_label[pos_cmp] != NULL; pos_cmp++) {
        if (my_strcmp(list_label[pos], list_label[pos_cmp]) == 0)
            (*count)++;
    }
}

bool count_nbr_label(char **list_label)
{
    size_t count = 0;

    for (size_t pos = 0; list_label[pos] != NULL; pos++) {
        count = 0;
        check(list_label, pos, &count);;
        if (count != 1)
            return true;
    }
    return false;
}
