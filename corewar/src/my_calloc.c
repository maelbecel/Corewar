/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** get_option
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"
#include <string.h>

void *my_calloc(int size)
{
    void *ptr = malloc(size);
    memset(ptr, 0, size);
    return ptr;
}
