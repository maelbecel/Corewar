/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

void zjmp(UNUSED vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    va_end(arg);
    if (!prog->carry) {
        for (size_t i = 0; i < 3; move_prog(prog), i++);
        return;
    }
    move_prog(prog);
    size_t jmp = get_param(vm, prog->coord, 2);
    printf("zjmp of %li(%i, %i)",jmp, prog->coord.y, prog->coord.x);
    for (size_t i = 0; i < (jmp - 1 % MEM_SIZE + IDX_MOD * 4); i++)
        move_prog(prog);
    printf(" to [%s] at (line %i, col %i)\n" ,int_to_hexa_string(vm->arene[prog->coord.y][prog->coord.x]),prog->coord.y, prog->coord.x);
}
