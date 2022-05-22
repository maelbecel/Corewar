/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** loop
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

char *getname(char *name)
{
    char **tab = my_str_to_word_array(name, '/');
    char *file = my_strdup(tab[my_strarraylen(tab) - 1]);
    for (int i = 0; tab[i]; free(tab[i]), i++);
    free(tab);
    return file;
}

bool check_win(int nb_live, vm_t *vm, champion_t *tmp)
{
    if (nb_live == 1) {
        my_printf("The player %i(%s) has won\n", tmp->prog_nb, getname(tmp->name));
        return true;
    } else if (nb_live == 0) {
        my_printf("Draw\n");
        return true;
    } else {
        vm->cycle_to_die -= CYCLE_DELTA;
        return false;
    }
}

bool win(vm_t *vm)
{
    int nb_live = 0;
    champion_t *tmp = NULL;

    if (vm->nb_cycle > vm->cycle_to_die) {
        my_printf("Draw\n");
        return true;
    }
    if (vm->nb_cycle != vm->cycle_to_die)
        return false;
    vm->nb_cycle = 0;
    for (int i = 0; vm->champ[i]; i++) {
        if (vm->champ[i]->live) {
            nb_live++;
            tmp = vm->champ[i];
            vm->champ[i]->live = false;
        } else
            vm->champ[i]->prog[0] = NULL;
    }
    return check_win(nb_live, vm, tmp);
}
