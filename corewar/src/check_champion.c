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
    for (int j = 0; vm->champ[j]; j++) {
        if (vm->champ[j]->prog_nb == x && vm->champ[j]->prog_nb != -1) {
            x++;
            j = -1;
        }
    }
    vm->champ[i]->prog_nb = x;
    return true;
}

bool check_adress(vm_t *vm, int i)
{
    int j = 1;
    for (; vm->champ[j]; j++);
    vm->champ[i]->load_address = (MEM_SIZE / j) * i;
    return true;
}

bool check_cmp(vm_t *vm)
{
    for (int i = 0; vm->champ[i]; i++) {
        if (vm->champ[i]->prog_nb == -1)
            check_number(vm, i);
        if (vm->champ[i]->load_address == -1)
            check_adress(vm, i);
        vm->champ[i]->prog[0]->reg[0] = vm->champ[i]->prog_nb;
    }
    verif_champ(vm);
    return true;
}
