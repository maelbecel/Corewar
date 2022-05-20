/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

static const codaction_t and_tab[] = {
    {AND_NN, and_nn},
    {AND_RR, and_rr},
    {AND_NR, and_nr},
    {AND_RN, and_rn},
    {AND_AN, and_an},
    {AND_AA, and_aa},
    {AND_NA, and_na},
    {AND_RA, and_ra},
    {AND_AR, and_ar},
    {0, NULL}
};

void and_nn(prog_t *prog, vm_t *vm)
{
    move_prog(prog);
    int nb1 = get_param(vm, prog->coord, 4);
    move_prog(prog), move_prog(prog), move_prog(prog), move_prog(prog);
    int nb2 = get_param(vm, prog->coord, 4);
    move_prog(prog), move_prog(prog), move_prog(prog), move_prog(prog);
    int reg = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg] = nb1 & nb2;
    prog->carry = (prog->reg[reg] == 0) ? 1 : 0;

}

void and_rr(prog_t *prog, vm_t *vm)
{
    move_prog(prog);
    int reg1 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    int reg2 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    int reg3 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg3] = prog->reg[reg1] & prog->reg[reg2];
    prog->carry = (prog->reg[reg3] == 0) ? 1 : 0;

}

void and_rn(prog_t *prog, vm_t *vm)
{
    move_prog(prog);
    int reg1 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    int nb = get_param(vm, prog->coord, 4);
    move_prog(prog), move_prog(prog), move_prog(prog), move_prog(prog);
    int reg2 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg2] = prog->reg[reg1] & nb;
    prog->carry = (prog->reg[reg2] == 0) ? 1 : 0;

}

void and_nr(prog_t *prog, vm_t *vm)
{
    move_prog(prog);
    int nb = get_param(vm, prog->coord, 4);
    move_prog(prog), move_prog(prog), move_prog(prog), move_prog(prog);
    int reg1 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    int reg2 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg2] = prog->reg[reg1] & nb;
    prog->carry = (prog->reg[reg2] == 0) ? 1 : 0;

}

void and(vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    int j = va_arg(arg, int);
    va_end(arg);
    move_prog(prog);
    int i = get_param(vm, prog->coord, 1);

    for (int x = 0; and_tab[x].code != 0; x++)
        if (and_tab[x].code == i) {
            and_tab[x].action(prog, vm);
            return;
        }
    del_prog(champ, j);
}
