/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

int endian(int nb)
{
    return ((nb & 0xff000000) >> 24) | ((nb & 0x00ff0000) >> 8) |
            ((nb & 0x0000ff00) << 8) | ((nb & 0x000000ff) << 24);
}
