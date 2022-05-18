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
        vm->champ[i]->prog[0]->coord = (coord_t)
                                        {vm->champ[i]->load_address % IDX_MOD,
                                        vm->champ[i]->load_address / IDX_MOD};
    }
    return true;
}