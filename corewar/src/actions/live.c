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
    champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    va_end(arg);
    move_prog(prog);

    int parm = get_param(vm, prog->coord, 4);

    my_printf("The player %i(%s) is alive\n", parm, getname(champ->name));
    for (int i = 0; vm->champ[i]; i++)
        if (vm->champ[i]->prog_nb == parm)
            vm->champ[i]->live = true;
    for (int i = 0; i < 4; i++)
        move_prog(prog);
}
