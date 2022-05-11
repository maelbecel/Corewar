/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** init_champ
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"

champion_t **init_champ(vm_t *vm)
{
    champion_t **champ = malloc(sizeof(champion_t *) * (vm->nb_champ + 1));

    champ[vm->nb_champ] = NULL;
    for (int i = 0; i < vm->nb_champ; i++) {
        champ[i] = malloc(sizeof(champion_t));
        champ[i]->prog_nb = -1;
        champ[i]->prog = init_prog(champ[i]->load_address, champ[i]->prog_nb);
        if (!champ[i]->prog)
            return NULL;
    }
    return champ;
}
