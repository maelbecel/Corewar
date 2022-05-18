/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"

void print_arene(vm_t *vm)
{
    for (int i = 0; i < NB_LINE; i++) {
        for (int j = 0; j < MEM_SIZE / NB_LINE; j++)
            my_printf((vm->arene[i][j] != 0) ? "\e[32m%s \e[0m": "%s ",
                                        int_to_hexa_string(vm->arene[i][j]));
        my_printf("\n");
    }
}
