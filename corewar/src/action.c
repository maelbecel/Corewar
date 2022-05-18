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

bool del_prog(champion_t *champ, int i)
{
    int x = i;

    for (; champ->prog[x + 1]; x++)
        champ->prog[x] = champ->prog[x + 1];
    champ->prog[x] = NULL;
    return true;
}

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
        return true;
    }
    if (op_tab[j + 1].code == 0) {
        move_prog(champ->prog[i]);
    }
    return false;
}

bool actions(vm_t *vm, champion_t *champ)
{
    for (int i = 0; champ->prog[i]; i++) {
        for (int j = 0; op_tab[j].code != 0; j++)
            if (get_action(vm, j, champ, i))
                break;
    }
    return true;
}
