/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** init_prog
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"

prog_t *init_prog(int load_ad, int prog_nb)
{
    prog_t *prog = malloc(sizeof(prog_t));

    prog->carry = 0;
    prog->coord = (coord_t) {load_ad % IDX_MOD, load_ad / 12};
    prog->current_cycle = 0;
    prog->goal_cycle = 0;
    prog->id_action = 0;
    for (int i = 0; i < REG_NUMBER; i++) {
        prog->reg[i] = i;
    }
    prog->reg[0] = prog_nb;
    return prog;
}