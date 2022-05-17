/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

void xor_nn(prog_t *prog,vm_t *vm)
{
    move_prog(prog);
    int nb1 = get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    int nb2 = get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    int reg = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg] = nb1 ^ nb2;
}

void xor_rr(prog_t *prog,vm_t *vm)
{
    move_prog(prog);
    int reg1 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    int reg2 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    int reg3 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg3] = prog->reg[reg1] ^ prog->reg[reg2];
}

void xor_rn(prog_t *prog,vm_t *vm)
{
    move_prog(prog);
    int reg1 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    int nb = get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    int reg2 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg2] = prog->reg[reg1] ^ nb;
}

void xor_nr(prog_t *prog,vm_t *vm)
{
    move_prog(prog);
    int nb = get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    int reg1 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    int reg2 = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg2] = prog->reg[reg1] ^ nb;
}

void xor_an(prog_t *prog,vm_t *vm)
{
    printf("[%s]", __FUNCTION__);
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
}

void xor_aa(prog_t *prog,vm_t *vm)
{
    printf("[%s]", __FUNCTION__);
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
}

void xor_na(prog_t *prog,vm_t *vm)
{
    printf("[%s]", __FUNCTION__);
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
}

void xor_ra(prog_t *prog,vm_t *vm)
{
    printf("[%s]", __FUNCTION__);
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
}

void xor_ar(prog_t *prog,vm_t *vm)
{
    printf("[%s]", __FUNCTION__);
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
}

void xor(vm_t *vm, ...)
{
    my_printf("xor\n");
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    va_end(arg);
    move_prog(prog);
    switch (get_param(vm, prog->coord, 1)) {
        case AND_NN : xor_nn(prog, vm);
            break;
        case AND_RR : xor_rr(prog, vm);
            break;
        case AND_NR : xor_nr(prog, vm);
            break;
        case AND_RN : xor_rn(prog, vm);
            break;
        case AND_AN : xor_an(prog, vm);
            break;
        case AND_AA : xor_aa(prog, vm);
            break;
        case AND_NA : xor_na(prog, vm);
            break;
        case AND_RA : xor_ra(prog, vm);
            break;
        case AND_AR : xor_ar(prog, vm);
            break;
    }
    printf("xor [%s] at (line %i, col %i)\n", int_to_hexa_string(vm->arene[prog->coord.y][prog->coord.x]),prog->coord.y, prog->coord.x);
}