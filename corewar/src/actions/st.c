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
    my_printf("st\n");
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    va_end(arg);
    move_prog(prog);

    int value = 0;
    int is_reg = get_param(vm, prog->coord, 1);
    move_prog(prog);
    int reg = get_param(vm, prog->coord, 1);
    move_prog(prog);
    if (is_reg == 80) {
        value = prog->reg[get_param(vm, prog->coord, 1)];
        move_prog(prog);
    } else {
        value = get_param(vm, prog->coord, 2);
        move_prog(prog), move_prog(prog);
    }
    printf("st r%i, %i", reg, value);
    prog->reg[reg] = value;
}