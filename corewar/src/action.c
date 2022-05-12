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

bool get_action(UNUSED vm_t *vm, int j, champion_t *champ, int c)
{
    if (c == op_tab[j].code) {
        printf("%s : code = %s -> %s with %i arg\n",champ->name , int_to_hexa_string(c) ,op_tab[j].mnemonique, op_tab[j].nbr_args);
        for (int i = 0; i < op_tab[j].nbr_args; i++)
            move_champs(champ);
    }
    return true;
}

bool actions(vm_t *vm, champion_t *champ)
{
    int c = 0;

    for (int i = 0; champ->prog[i]; i++) {
        c = vm->arene[vm->champ[i]->prog[0]->coord.y][vm->champ[i]->prog[0]->coord.x];
        for (int j = 0; op_tab[j].code != 0; j++)
            get_action(vm, j, champ, c);
    }
    return true;
}