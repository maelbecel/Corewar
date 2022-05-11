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
    prog->pc = load_ad;
    prog->reg = malloc(REG_SIZE * REG_NUMBER);
    if (!prog->reg)
        return NULL;
    for (int i = 0; i < REG_NUMBER; i++) {
        prog->reg[i] = 0;
    }
    prog->reg[0] = prog_nb;
    return prog;
}