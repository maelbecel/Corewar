/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

void add(vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    int nb = 0;
    int reg1 = 0;
    int reg2 = 0;
    int reg3 = 0;

    va_end(arg);
    move_prog(prog), move_prog(prog);
    reg1 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    reg2 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    reg3 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    nb = prog->reg[reg2] + prog->reg[reg1];
    prog->carry = (nb == 0) ? 1 : 0;
    prog->reg[reg3] = nb;
}
