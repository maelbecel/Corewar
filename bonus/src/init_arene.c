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

unsigned char **init_arene(void)
{
    unsigned char **arene = malloc(MEM_SIZE);
    for (int i = 0; i < NB_LINE; i++)
        arene[i] = my_calloc(MEM_SIZE / NB_LINE);
    return arene;
}