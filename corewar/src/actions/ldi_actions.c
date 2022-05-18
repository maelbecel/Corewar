/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

void ldi_an(vm_t *vm, prog_t *prog)
{
    int value = 0;
    int reg = 0;
    int pos = 0;

    move_prog(prog);
    value = get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    value = (prog->coord.y * IDX_MOD + prog->coord.x + value - 4);
    value = vm->arene[value / IDX_MOD][value % IDX_MOD];
    value += get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    reg = get_param(vm, prog->coord, 1) - 1;
    pos = (prog->coord.y * IDX_MOD + prog->coord.x + value - 6 % IDX_MOD);
    prog->reg[reg] = vm->arene[pos / IDX_MOD][pos % IDX_MOD];
    move_prog(prog);
}

void ldi_nn(vm_t *vm, prog_t *prog)
{
    int value = 0;
    int reg = 0;
    int pos = 0;

    move_prog(prog);
    value = get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    value += get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    reg = get_param(vm, prog->coord, 1) - 1;
    pos = (prog->coord.y * IDX_MOD + prog->coord.x + value - 6 % IDX_MOD);
    prog->reg[reg] = vm->arene[pos / IDX_MOD][pos % IDX_MOD];
    move_prog(prog);
}

void ldi_ar(vm_t *vm, prog_t *prog)
{
    int value = 0;
    int reg = 0;
    int pos = 0;

    move_prog(prog);
    value = get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    value = (prog->coord.y * IDX_MOD + prog->coord.x + value - 4);
    value = vm->arene[value / IDX_MOD][value % IDX_MOD];
    value += prog->reg[get_param(vm, prog->coord, 1) - 1];
    move_prog(prog);
    reg = get_param(vm, prog->coord, 1) - 1;
    pos = (prog->coord.y * IDX_MOD + prog->coord.x + value - 6 % IDX_MOD);
    prog->reg[reg] = vm->arene[pos / IDX_MOD][pos % IDX_MOD];
    move_prog(prog);
}

void ldi_rr(vm_t *vm, prog_t *prog)
{
    int value = 0;
    int reg = 0;
    int pos = 0;

    move_prog(prog);
    value = prog->reg[get_param(vm, prog->coord, 1) - 1];
    move_prog(prog);
    value += get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    reg = get_param(vm, prog->coord, 1) - 1;
    pos = (prog->coord.y * IDX_MOD + prog->coord.x + value - 6 % IDX_MOD);
    prog->reg[reg] = vm->arene[pos / IDX_MOD][pos % IDX_MOD];
    move_prog(prog);
}

void ldi_rn(vm_t *vm, prog_t *prog)
{
    int value = 0;
    int reg = 0;
    int pos = 0;

    move_prog(prog);
    value = prog->reg[get_param(vm, prog->coord, 1) - 1];
    move_prog(prog);
    value += prog->reg[get_param(vm, prog->coord, 1) - 1];
    move_prog(prog);
    reg = get_param(vm, prog->coord, 1) - 1;
    pos = (prog->coord.y * IDX_MOD + prog->coord.x + value - 6 % IDX_MOD);
    prog->reg[reg] = vm->arene[pos / IDX_MOD][pos % IDX_MOD];
    move_prog(prog);
}
