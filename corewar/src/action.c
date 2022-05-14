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

bool get_action(vm_t *vm, int j, champion_t *champ, int i)
{
    int c = vm->arene[champ->prog[i]->coord.y][champ->prog[i]->coord.x];

    if (c == op_tab[j].code) {
        champ->prog[i]->goal_cycle = op_tab[j].nbr_cycles;
        champ->prog[i]->current_cycle += 1;
        if (champ->prog[i]->goal_cycle == champ->prog[i]->current_cycle) {
            op_tab[j].func(vm, champ, champ->prog[i]);
            champ->prog[i]->current_cycle = 0;
        }
    }
    return true;
}

bool actions(vm_t *vm, champion_t *champ)
{
    for (int i = 0; champ->prog[i]; i++) {
        for (int j = 0; op_tab[j].code != 0; j++)
            get_action(vm, j, champ, i);
    }
    return true;
}
