/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

void st(vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    va_end(arg);
    move_prog(prog);

    int value = 0;
    int is_reg = get_param(vm, prog->coord, 1);
    move_prog(prog);
    int reg = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    if (is_reg == 80) {
        value = prog->reg[get_param(vm, prog->coord, 1) - 1];
        move_prog(prog);
        prog->reg[reg] = value;
        return;
    } else {
        value = get_param(vm, prog->coord, 2);
        move_prog(prog), move_prog(prog);
        int adress = (prog->coord.y * IDX_MOD + prog->coord.x + value - 4);
        vm->arene[adress / IDX_MOD][adress % IDX_MOD] = prog->reg[reg];
    }
}
