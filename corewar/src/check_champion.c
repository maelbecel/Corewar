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

bool same_prog(vm_t *vm, int prog, int x)
{
    for (int i = 0; vm->champ[i]; i++)
        if (vm->champ[i]->prog_nb == prog && i != x)
            return true;
    return false;
}

bool same_adress(vm_t *vm, int prog, int x)
{
    for (int i = 0; vm->champ[i]; i++)
        if (vm->champ[i]->load_address == prog && i != x)
            return true;
    return false;
}

bool verif_champ(vm_t *vm)
{
    for (int i = 0; vm->champ[i]; i++) {
        if (same_prog(vm, vm->champ[i]->prog_nb, i))
            error("Duplicate champion number\n");
        if (same_adress(vm, vm->champ[i]->load_address, i))
            error("Duplicate champion address\n");
    }
    return true;
}

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
    }
    verif_champ(vm);
    return true;
}
