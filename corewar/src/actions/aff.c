/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

void aff(vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    va_end(arg);

    move_prog(prog);
    int reg = get_param(vm, prog->coord, 2) % 256;
    my_printf("aff r%i -> %c(%i)\n",reg ,prog->reg[reg - 1], prog->reg[reg - 1]);

    for (int i = 0; i < 2; i++)
        move_prog(prog);
}