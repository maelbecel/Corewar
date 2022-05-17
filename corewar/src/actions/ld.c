/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

void ld(vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    va_end(arg);
    move_prog(prog);
    int is_long = get_param(vm, prog->coord, 1);
    move_prog(prog);
    int value = 0;

    if (is_long == 0x90) {
        int adress = (prog->coord.y * IDX_MOD + prog->coord.x + get_param(vm, prog->coord, 4) - 2);
        value = get_param(vm, (coord_t){adress / IDX_MOD, adress % IDX_MOD}, 1);
        move_prog(prog), move_prog(prog), move_prog(prog), move_prog(prog);
    } else {
        value = get_param(vm, prog->coord, 2);
        move_prog(prog), move_prog(prog);
    }
    int reg = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg] = value % IDX_MOD;
    prog->carry = 1;
}