/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** loop
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

bool win(vm_t *vm)
{
    int nb_live = 0;

    if (vm->nb_cycle != vm->cycle_to_die)
        return false;
    vm->nb_cycle = 0;
    for (int i = 0; vm->champ[i]; i++) {
        if (vm->champ[i]->live) {
            nb_live++;
        } else {
            vm->champ[i]->prog[0] = NULL;
        }
    }
    if (nb_live == 1) {
        my_printf("win\n");
        return true;
    } else if (nb_live == 0) {
        my_printf("draw\n");
        return true;
    } else {
        vm->cycle_to_die -= CYCLE_DELTA;
        return false;
    }
}
