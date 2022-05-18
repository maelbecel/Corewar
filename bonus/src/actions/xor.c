/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

static const codaction_t xor_tab[] = {
    {AND_NN, xor_nn},
    {AND_RR, xor_rr},
    {AND_NR, xor_nr},
    {AND_RN, xor_rn},
    {AND_AN, xor_an},
    {AND_AA, xor_aa},
    {AND_NA, xor_na},
    {AND_RA, xor_ra},
    {AND_AR, xor_ar},
    {0, NULL}
};

void xor_nr(prog_t *prog, vm_t *vm)
{
    move_prog(prog);
    int nb = get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    int reg1 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    int reg2 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg2] = prog->reg[reg1] ^ nb;
    prog->carry = (prog->reg[reg2] == 0) ? 1 : 0;
}

void xor_nn(prog_t *prog, vm_t *vm)
{
    move_prog(prog);
    int nb1 = get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    int nb2 = get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    int reg = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg] = nb1 ^ nb2;
    prog->carry = (prog->reg[reg] == 0) ? 1 : 0;
}

void xor_rr(prog_t *prog, vm_t *vm)
{
    move_prog(prog);
    int reg1 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    int reg2 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    int reg3 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg3] = prog->reg[reg1] ^ prog->reg[reg2];
    prog->carry = (prog->reg[reg3] == 0) ? 1 : 0;
}

void xor_rn(prog_t *prog, vm_t *vm)
{
    move_prog(prog);
    int reg1 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    int nb = get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    int reg2 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg2] = prog->reg[reg1] ^ nb;
    prog->carry = (prog->reg[reg2] == 0) ? 1 : 0;
}

void xor(vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    va_end(arg);
    move_prog(prog);
    int i = get_param(vm, prog->coord, 1);

    for (int x = 0; xor_tab[x].code != 0; x++)
        if (xor_tab[x].code == i)
            xor_tab[x].action(prog, vm);
}
