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

static bool get_champ(champion_t *champ, vm_t *vm)
{
    int x = 0;
    int y = 0;
    struct stat file;

    if (stat(champ->name, &file) == -1)
        return false;
    champ->buffer += sizeof(header_t);
    for (long unsigned int i = 0; i < file.st_size - sizeof(header_t); i++) {
        x = (champ->load_address + i) / IDX_MOD;
        y = (champ->load_address + i) % IDX_MOD;
        vm->arene[x][y] = champ->buffer[i];
    }
    return true;
}

bool fill_champ(vm_t *vm)
{
    for (int i = 0; vm->champ[i]; i++)
        get_champ(vm->champ[i], vm);
    return true;
}