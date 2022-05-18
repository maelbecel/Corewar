/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

static const codaction_t or_tab[] = {
    {AND_NN, or_nn},
    {AND_RR, or_rr},
    {AND_NR, or_nr},
    {AND_RN, or_rn},
    {AND_AN, or_an},
    {AND_AA, or_aa},
    {AND_NA, or_na},
    {AND_RA, or_ra},
    {AND_AR, or_ar},
    {0, NULL}
};

void or_nn(prog_t *prog, vm_t *vm)
{
    move_prog(prog);
    int nb1 = get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    int nb2 = get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    int reg = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg] = nb1 | nb2;
    prog->carry = (prog->reg[reg] == 0) ? 1 : 0;
}

void or_rr(prog_t *prog, vm_t *vm)
{
    move_prog(prog);
    int reg1 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    int reg2 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    int reg3 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg3] = prog->reg[reg1] | prog->reg[reg2];
    prog->carry = (prog->reg[reg3] == 0) ? 1 : 0;
}

void or_rn(prog_t *prog, vm_t *vm)
{
    move_prog(prog);
    int reg1 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    int nb = get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    int reg2 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg2] = prog->reg[reg1] | nb;
    prog->carry = (prog->reg[reg2] == 0) ? 1 : 0;
}

void or_nr(prog_t *prog, vm_t *vm)
{
    move_prog(prog);
    int nb = get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    int reg1 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    int reg2 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg2] = prog->reg[reg1] | nb;
    prog->carry = (prog->reg[reg2] == 0) ? 1 : 0;
}

void or(vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    va_end(arg);
    move_prog(prog);
    int i = get_param(vm, prog->coord, 1);

    for (int x = 0; or_tab[x].code != 0; x++)
        if (or_tab[x].code == i)
            or_tab[x].action(prog, vm);
}
