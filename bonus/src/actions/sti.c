/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

void sti_rr(vm_t *vm, prog_t *prog)
{
    int res;
    int nb;
    int reg;
    int adress;

    move_prog(prog);
    reg = get_param(vm, prog->coord, 1);
    move_prog(prog);
    nb = get_param(vm, prog->coord, 1);
    move_prog(prog);
    nb += get_param(vm, prog->coord, 1);
    move_prog(prog);
    adress = (prog->coord.y * IDX_MOD + prog->coord.x + nb - 5);
    res = endian(prog->reg[reg - 1]);
    vm->arene[adress / IDX_MOD][adress % IDX_MOD] = res;
    vm->arene[(adress + 1) / IDX_MOD][(adress + 1) % IDX_MOD] = res >> 8;
    vm->arene[(adress + 2) / IDX_MOD][(adress + 2) % IDX_MOD] = res >> 16;
    vm->arene[(adress + 3) / IDX_MOD][(adress + 3) % IDX_MOD] = res >> 24;
}

void sti_nn(vm_t *vm, prog_t *prog)
{
    int res;
    int nb;
    int adress;
    int reg;

    move_prog(prog);
    reg = get_param(vm, prog->coord, 1);
    move_prog(prog);
    nb = get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    nb += get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    adress = (prog->coord.y * IDX_MOD + prog->coord.x + nb - 7);
    res = endian(prog->reg[reg - 1]);
    vm->arene[adress / IDX_MOD][adress % IDX_MOD] = res;
    vm->arene[(adress + 1) / IDX_MOD][(adress + 1) % IDX_MOD] = res >> 8;
    vm->arene[(adress + 2) / IDX_MOD][(adress + 2) % IDX_MOD] = res >> 16;
    vm->arene[(adress + 3) / IDX_MOD][(adress + 3) % IDX_MOD] = res >> 24;
}

void sti_nr(vm_t *vm, prog_t *prog)
{
    int res;
    int nb;
    int adress;
    int reg;

    move_prog(prog);
    reg = get_param(vm, prog->coord, 1);
    move_prog(prog);
    nb = get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    nb += get_param(vm, prog->coord, 1);
    move_prog(prog);
    adress = (prog->coord.y * IDX_MOD + prog->coord.x + nb - 6);
    res = endian(prog->reg[reg - 1]);
    vm->arene[adress / IDX_MOD][adress % IDX_MOD] = res;
    vm->arene[(adress + 1) / IDX_MOD][(adress + 1) % IDX_MOD] = res >> 8;
    vm->arene[(adress + 2) / IDX_MOD][(adress + 2) % IDX_MOD] = res >> 16;
    vm->arene[(adress + 3) / IDX_MOD][(adress + 3) % IDX_MOD] = res >> 24;
}

void sti_rn(vm_t *vm, prog_t *prog)
{
    int res;
    int nb;
    int adress;
    int reg;

    move_prog(prog);
    reg = get_param(vm, prog->coord, 1);
    move_prog(prog);
    nb = get_param(vm, prog->coord, 1);
    move_prog(prog);
    nb += get_param(vm, prog->coord, 2);
    move_prog(prog);
    move_prog(prog);
    adress = (prog->coord.y * IDX_MOD + prog->coord.x + nb - 6);
    res = endian(prog->reg[reg - 1]);
    vm->arene[adress / IDX_MOD][adress % IDX_MOD] = res;
    vm->arene[(adress + 1) / IDX_MOD][(adress + 1) % IDX_MOD] = res >> 8;
    vm->arene[(adress + 2) / IDX_MOD][(adress + 2) % IDX_MOD] = res >> 16;
    vm->arene[(adress + 3) / IDX_MOD][(adress + 3) % IDX_MOD] = res >> 24;
}

void sti(vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    va_end(arg);
    move_prog(prog);
    switch (get_param(vm, prog->coord, 1)) {
        case STI_RR: sti_rr(vm, prog);
            break;
        case STI_NN: sti_nn(vm, prog);
            break;
        case STI_RN: sti_rn(vm, prog);
            break;
        case STI_NR: sti_nr(vm, prog);
            break;
        default: error("sti: unknown instruction\n");
    }
}
