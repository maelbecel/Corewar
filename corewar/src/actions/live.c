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

    my_printf("live for %x\n", int_from_byte(vm, prog->coord));
    for (int i = 0; i < 4; i++)
        move_champs(champ);
    va_end(arg);
}
