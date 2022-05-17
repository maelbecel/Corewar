/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

void lldi_an(vm_t *vm, prog_t *prog)
{
    move_prog(prog);
    int value = get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    value = (prog->coord.y * IDX_MOD + prog->coord.x + value - 4);
    value = vm->arene[value / IDX_MOD][value % IDX_MOD];
    value += get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    int reg = get_param(vm, prog->coord, 1) - 1;
    int pos = (prog->coord.y * IDX_MOD + prog->coord.x + value - 6);
    prog->reg[reg] = vm->arene[pos / IDX_MOD][pos % IDX_MOD];
    move_prog(prog);
}

void lldi_nn(vm_t *vm, prog_t *prog)
{
    move_prog(prog);
    int value = get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    value += get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    int reg = get_param(vm, prog->coord, 1) - 1;
    int pos = (prog->coord.y * IDX_MOD + prog->coord.x + value - 6);
    prog->reg[reg] = vm->arene[pos / IDX_MOD][pos % IDX_MOD];
    move_prog(prog);
}

void lldi_ar(vm_t *vm, prog_t *prog)
{
    move_prog(prog);
    int value = get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    value = (prog->coord.y * IDX_MOD + prog->coord.x + value - 4);
    value = vm->arene[value / IDX_MOD][value % IDX_MOD];
    value += prog->reg[get_param(vm, prog->coord, 1) - 1];
    move_prog(prog);
    int reg = get_param(vm, prog->coord, 1) - 1;
    int pos = (prog->coord.y * IDX_MOD + prog->coord.x + value - 6);
    prog->reg[reg] = vm->arene[pos / IDX_MOD][pos % IDX_MOD];
    move_prog(prog);
}

void lldi_rr(vm_t *vm, prog_t *prog)
{
    move_prog(prog);
    int value = prog->reg[get_param(vm, prog->coord, 1) - 1];
    move_prog(prog);
    value += get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    int reg = get_param(vm, prog->coord, 1) - 1;
    int pos = (prog->coord.y * IDX_MOD + prog->coord.x + value - 6);
    prog->reg[reg] = vm->arene[pos / IDX_MOD][pos % IDX_MOD];
    move_prog(prog);
}

void lldi_rn(vm_t *vm, prog_t *prog)
{
    move_prog(prog);
    int value = prog->reg[get_param(vm, prog->coord, 1) - 1];
    move_prog(prog);
    value += prog->reg[get_param(vm, prog->coord, 1) - 1];
    move_prog(prog);
    int reg = get_param(vm, prog->coord, 1) - 1;
    int pos = (prog->coord.y * IDX_MOD + prog->coord.x + value - 6);
    prog->reg[reg] = vm->arene[pos / IDX_MOD][pos % IDX_MOD];
    move_prog(prog);
}

void lldi(vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    va_end(arg);
    move_prog(prog);

    switch(get_param(vm, prog->coord, 1)) {
        case LDI_AN: lldi_an(vm, prog);
            break;
        case LDI_NN: lldi_nn(vm, prog);
            break;
        case LDI_AR: lldi_ar(vm, prog);
            break;
        case LDI_RR: lldi_rr(vm, prog);
            break;
        case LDI_RN: lldi_rn(vm, prog);
            break;
    }
    prog->carry = 1;
}