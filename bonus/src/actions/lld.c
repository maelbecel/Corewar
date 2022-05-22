/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

static int short_value(vm_t *vm, prog_t *prog)
{
    int value = 0;

    value = get_param(vm, prog->coord, 2);
    move_prog(prog), move_prog(prog);
    return value;
}

static int long_value(vm_t *vm, prog_t *prog)
{
    int value = 0;
    coord_t coord = prog->coord;
    int adress = (prog->coord.y * IDX_MOD + prog->coord.x +
                                            get_param(vm, prog->coord, 4) - 2);

    coord.x = adress % IDX_MOD;
    coord.y = adress / IDX_MOD;
    value = get_param(vm, coord, 1);
    move_prog(prog), move_prog(prog), move_prog(prog), move_prog(prog);
    return value;
}

void do_lld(vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    int i = va_arg(arg, int);
    va_end(arg);
    int is_long = 0;
    int reg = 0;
    int value = 0;

    move_prog(prog);
    is_long = get_param(vm, prog->coord, 1);
    move_prog(prog);
    value = (is_long == 0x90) ? long_value(vm, prog) : value;
    value = (is_long == 0x90) ? short_value(vm, prog) : value;
    reg = get_param(vm, prog->coord, 1) - 1;
    move_prog(prog);
    prog->reg[reg] = value;
    prog->carry = 1;
    if (value == -1)
        del_prog(champ, i);
}
