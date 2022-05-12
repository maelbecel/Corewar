/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

void live(UNUSED vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    UNUSED int player = va_arg(arg, int);
    my_printf("live for %s\n", int_to_hexa_string(player));
    va_end(arg);
}
