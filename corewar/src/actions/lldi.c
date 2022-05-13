/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

void lldi(UNUSED vm_t *vm, ...)
{
    my_printf("lldi\n");
    va_list arg;
    va_start(arg, vm);
    champion_t *champ = va_arg(arg, champion_t *);
    va_end(arg);
    for (int i = 0; i < 3; i++)
        move_champs(champ);
}