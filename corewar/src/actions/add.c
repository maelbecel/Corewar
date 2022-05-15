/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

void add(UNUSED vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    va_end(arg);
    move_prog(prog);
    move_prog(prog);
    int reg1 = get_param(vm, prog->coord, 1);
    move_prog(prog);
    int reg2 = get_param(vm, prog->coord, 1);
    move_prog(prog);
    int reg3 = get_param(vm, prog->coord, 1);
    move_prog(prog);
    printf("add r%i(%i) + r%i(%i) -> r%i now on %x (%i, %i)\n", reg1, prog->reg[reg1] , reg2, prog->reg[reg2] ,reg3, vm->arene[prog->coord.y][prog->coord.x], prog->coord.y, prog->coord.x);
    prog->reg[reg3] = prog->reg[reg2] + prog->reg[reg1];
}