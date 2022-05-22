/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

void do_ldi(vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    int i = va_arg(arg, int);
    va_end(arg);
    move_prog(prog);

    switch (get_param(vm, prog->coord, 1)) {
        case LDI_AN: ldi_an(vm, prog);
            break;
        case LDI_NN: ldi_nn(vm, prog);
            break;
        case LDI_AR: ldi_ar(vm, prog);
            break;
        case LDI_RR: ldi_rr(vm, prog);
            break;
        case LDI_RN: ldi_rn(vm, prog);
            break;
        default: del_prog(champ, i);
            return;
    }
    prog->carry = 1;
}
