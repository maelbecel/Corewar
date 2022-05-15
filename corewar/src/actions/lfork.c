/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

int long_reset_prog(champion_t *champ, coord_t co, int adress)
{
    int size = 0;
    int i = 0;
    prog_t **new;
    for(;champ->prog[size] ; size++);
    new = malloc(sizeof(prog_t *) * (size + 2));
    for (; i < size; new[i] = champ->prog[i], i++);
    new[i] = init_prog(1, champ->prog_nb);
    new[i]->coord = (coord_t){co.x, co.y};
    new[i + 1] = NULL;
    for (int x = 0; x < (adress - 1) % MEM_SIZE; x++)
        move_prog(new[i]);
    free(champ->prog);
    champ->prog = new;
    my_printf("nb process is now %d\n", size + 1);
    return i;
}

void lfork(UNUSED vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    va_end(arg);
    move_prog(prog);
    int adress = (get_param(vm, prog->coord, 2));
    printf("long fork in %x(%i) ", adress, adress);
    int x = long_reset_prog(champ, prog->coord, adress);
    printf("to [%s] at (line %i, col %i)\n", int_to_hexa_string(vm->arene[champ->prog[x]->coord.y][champ->prog[x]->coord.x]),champ->prog[x]->coord.y, champ->prog[x]->coord.x);
    for (int i = 0; i < 2; i++)
        move_prog(prog);
}