/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

int reset_prog(champion_t *champ, coord_t co, int adress)
{
    int size = 0;
    int i = 0;
    prog_t **new;

    for (; champ->prog[size]; size++);
    new = malloc(sizeof(prog_t *) * (size + 2));
    for (; i < size; new[i] = champ->prog[i], i++);
    new[i] = init_prog(1, champ->prog_nb);
    new[i]->coord = (coord_t){co.x, co.y};
    new[i + 1] = NULL;
    for (int x = 0; x < (adress - 1) % IDX_MOD; x++)
        move_prog(new[i]);
    free(champ->prog);
    champ->prog = new;
    return i;
}

void a_fork(vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    int adress = 0;

    va_end(arg);
    move_prog(prog);
    adress = get_param(vm, prog->coord, 2);
    reset_prog(champ, prog->coord, adress);
    move_prog(prog), move_prog(prog);
}