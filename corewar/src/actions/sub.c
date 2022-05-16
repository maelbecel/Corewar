/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

void sub(UNUSED vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    int nb = 0;
    va_end(arg);
    move_prog(prog);
    move_prog(prog);
    int reg1 = get_param(vm, prog->coord, 1);
    move_prog(prog);
    int reg2 = get_param(vm, prog->coord, 1);
    move_prog(prog);
    int reg3 = get_param(vm, prog->coord, 1);
    move_prog(prog);
    printf("sub r%i(%i) - r%i(%i) -> r%i\n", reg1, prog->reg[reg1] , reg2, prog->reg[reg2] ,reg3);
    if (nb == 0)
        prog->carry = 1;
    else
        prog->carry = 0;
    prog->reg[reg3] = nb;
}