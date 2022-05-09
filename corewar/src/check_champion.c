/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** get_option
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"

bool check_number(vm_t *vm, int i)
{
    int x = 0;
    if (vm->champions[i]->prog_nb == -1) {
        for (int j = 0; vm->champions[j]; j++) {
            x = (vm->champions[j]->prog_nb == x && vm->champions[j]->prog_nb != -1) ? x + 1 : x;
            j = (vm->champions[j]->prog_nb == x - 1 && vm->champions[j]->prog_nb != -1) ? -1 : j;
        }
        vm->champions[i]->prog_nb = x;
    }
    return true;
}

bool check_cmp(vm_t *vm)
{
    for (int i = 0; vm->champions[i]; i++) {
        check_number(vm, i);
    }
    return true;
}
