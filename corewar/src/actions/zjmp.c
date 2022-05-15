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
    move_prog(prog);
    size_t jmp = get_param(vm, prog->coord, 2);
    for (size_t i = 0; i < (jmp - 1 % MEM_SIZE); i++)
        move_prog(prog);
    printf("zjmp of %li to [%s] at (line %i, col %i)\n",jmp ,int_to_hexa_string(vm->arene[prog->coord.y][prog->coord.x]),prog->coord.y, prog->coord.x);
}
