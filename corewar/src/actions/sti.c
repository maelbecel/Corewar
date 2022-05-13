/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

void sti(UNUSED vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    va_end(arg);
    for (int i = 0; i < 7; i++)
        move_prog(prog);
    printf("sti to [%s] at (line %i, col %i)\n", int_to_hexa_string(vm->arene[prog->coord.y][prog->coord.x]),prog->coord.y, prog->coord.x);
}