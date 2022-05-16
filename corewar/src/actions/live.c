/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

int int_from_byte(vm_t *vm, coord_t coord)
{
    int res = 0;
    char add;
    void *arrene = &vm->arene[coord.y][coord.x];

    for (int i = 0; i < 4; i++) {
        add = (*((char *)((size_t)arrene + i))) & 0xFF;
        res |= (add << (8 * i));
    }
    return res;
}

void live(vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    va_end(arg);
    move_prog(prog);

    int parm = get_param(vm, prog->coord, 4);

    for (int i = 0; vm->champ[i]; i++)
        if (vm->champ[i]->prog_nb == parm)
            vm->champ[i]->live = true;
    printf("live for %i(%x %x %x %x) ", parm, vm->arene[prog->coord.y][prog->coord.x], vm->arene[prog->coord.y][prog->coord.x + 1], vm->arene[prog->coord.y][prog->coord.x + 2], vm->arene[prog->coord.y][prog->coord.x + 3]);
    for (int i = 0; i < 4; i++)
        move_prog(prog);
    printf("to [%s] at (line %i, col %i)\n", int_to_hexa_string(vm->arene[prog->coord.y][prog->coord.x]),prog->coord.y, prog->coord.x);
}
