/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

size_t get_param(vm_t *vm, coord_t coord, size_t size)
{
    size_t res = 0;

    for (size_t i = 0; i < size; i++) {
        if (coord.x >= IDX_MOD) {
            coord.y += (coord.x / IDX_MOD);
            coord.x %= IDX_MOD;
            coord.y %= 12;
        }
        res |= ACT_CASE(vm, coord.x, coord.y);
        if (i + 1 < size)
            res <<= 8;
        coord.x++;
    }
    return res;
}
