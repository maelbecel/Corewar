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

int init_champ(champion_t *champ)
{
    champ->prog = init_prog(champ->load_address, champ->prog_nb);
    if (!champ->prog)
        return -1;
    champ->buffer = get_data(champ);
    if (!champ->buffer)
        return -1;
    return 0;
}
