/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

void lldi(vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    va_end(arg);
    move_prog(prog);

    switch (get_param(vm, prog->coord, 1)) {
        case LDI_AN: lldi_an(vm, prog);
            break;
        case LDI_NN: lldi_nn(vm, prog);
            break;
        case LDI_AR: lldi_ar(vm, prog);
            break;
        case LDI_RR: lldi_rr(vm, prog);
            break;
        case LDI_RN: lldi_rn(vm, prog);
            break;
    }
    prog->carry = 1;
}