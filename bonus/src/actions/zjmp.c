/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

void do_zjmp(UNUSED vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    int i = va_arg(arg, int);
    size_t jmp;

    va_end(arg);
    if (!prog->carry) {
        for (size_t i = 0; i < 3; move_prog(prog), i++);
        return;
    }
    move_prog(prog);
    jmp = get_param(vm, prog->coord, 2);
    for (size_t i = 0; i < (jmp - 1 % MEM_SIZE + IDX_MOD * 4); i++)
        move_prog(prog);
    if (vm->arene[prog->coord.y][prog->coord.x] > 0x0f)
        del_prog(champ, i);
}
