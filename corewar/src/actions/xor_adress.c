/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

void xor_an(prog_t *prog, vm_t *vm)
{
    move_prog(prog);
    int value = get_param(vm, prog->coord, 2);
    int adress = (prog->coord.y * IDX_MOD + prog->coord.x + value - 2);
    adress = vm->arene[adress / IDX_MOD][adress % IDX_MOD];
    move_prog(prog), move_prog(prog);
    int nb = get_param(vm, prog->coord, 4);
    move_prog(prog), move_prog(prog), move_prog(prog), move_prog(prog);
    int reg2 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg2] = adress ^ nb;
    prog->carry = (prog->reg[reg2] == 0) ? 1 : 0;
}

void xor_aa(prog_t *prog, vm_t *vm)
{
    move_prog(prog);
    int value = get_param(vm, prog->coord, 2);
    int ad1 = (prog->coord.y * IDX_MOD + prog->coord.x + value - 2);
    ad1 = vm->arene[ad1 / IDX_MOD][ad1 % IDX_MOD];
    move_prog(prog), move_prog(prog);
    value = get_param(vm, prog->coord, 2);
    int ad2 = (prog->coord.y * IDX_MOD + prog->coord.x + value - 4);
    ad2 = vm->arene[ad2 / IDX_MOD][ad2 % IDX_MOD];
    move_prog(prog), move_prog(prog);
    int reg2 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg2] = ad1 ^ ad2;
    prog->carry = (prog->reg[reg2] == 0) ? 1 : 0;
}

void xor_na(prog_t *prog, vm_t *vm)
{
    move_prog(prog);
    int nb = get_param(vm, prog->coord, 4);
    move_prog(prog), move_prog(prog), move_prog(prog), move_prog(prog);
    int value = get_param(vm, prog->coord, 2);
    int ad2 = (prog->coord.y * IDX_MOD + prog->coord.x + value - 6);
    ad2 = vm->arene[ad2 / IDX_MOD][ad2 % IDX_MOD];
    move_prog(prog), move_prog(prog);
    int reg2 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg2] = nb ^ ad2;
    prog->carry = (prog->reg[reg2] == 0) ? 1 : 0;
}

void xor_ra(prog_t *prog, vm_t *vm)
{
    move_prog(prog);
    int reg1 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    int value = get_param(vm, prog->coord, 2);
    int ad2 = (prog->coord.y * IDX_MOD + prog->coord.x + value - 3);
    ad2 = vm->arene[ad2 / IDX_MOD][ad2 % IDX_MOD];
    move_prog(prog), move_prog(prog);
    int reg2 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg2] = prog->reg[reg1] ^ ad2;
    prog->carry = (prog->reg[reg2] == 0) ? 1 : 0;
}

void xor_ar(prog_t *prog, vm_t *vm)
{
    move_prog(prog);
    int value = get_param(vm, prog->coord, 2);
    int ad2 = (prog->coord.y * IDX_MOD + prog->coord.x + value - 2);
    ad2 = vm->arene[ad2 / IDX_MOD][ad2 % IDX_MOD];
    move_prog(prog), move_prog(prog);
    int reg1 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    int reg2 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg2] = prog->reg[reg1] ^ ad2;
    prog->carry = (prog->reg[reg2] == 0) ? 1 : 0;
}
