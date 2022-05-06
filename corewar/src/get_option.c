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

int get_cycle(char **av, int i)
{
    int cycle = 0;
    if (my_str_isnum(av[i + 1])) {
        my_printf("test\n");
        cycle = my_getnbr(av[i + 1]);
        if (cycle == 0)
            return CYCLE_TO_DIE;
        else
            return cycle;
    }
    return CYCLE_TO_DIE;
}

bool get_dump(char **av, vm_t *vm)
{
    for (int i = 0; av[i]; i++) {
        if (my_strcmp(av[i], "-dump") == 0) {
            vm->nb_cycle = get_cycle(av, i);
            return false;
        }
    }
    return true;
}

bool get_option(char **av, vm_t *vm)
{
    get_dump(av, vm);
    return false;
}