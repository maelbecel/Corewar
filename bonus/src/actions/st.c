/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

static void registre(int reg, vm_t *vm, prog_t *prog)
{
    int value = prog->reg[get_param(vm, prog->coord, 1) - 1];

    move_prog(prog);
    prog->reg[reg] = value;
}

static void adresse(int reg, vm_t *vm, prog_t *prog)
{
    int value = get_param(vm, prog->coord, 2);
    int adress = 0;

    move_prog(prog), move_prog(prog);
    adress = (prog->coord.y * IDX_MOD + prog->coord.x + value - 4);
    vm->arene[adress / IDX_MOD][adress % IDX_MOD] = prog->reg[reg];
}

void st(vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    va_end(arg);
    int is_reg = 0;
    int reg = 0;

    move_prog(prog);
    is_reg = get_param(vm, prog->coord, 1);
    move_prog(prog);
    reg = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    if (is_reg == 80)
        registre(reg, vm, prog);
    else
        adresse(reg, vm, prog);
}