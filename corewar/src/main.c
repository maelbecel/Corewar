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

static bool usage(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        my_printf("help\n./corewar [-dump nbr_cycle] [[-n prog_number] ");
        my_printf("[-a load_address] prog_name] ...\nDESCRIPTION\n");
        my_printf("-dump nbr_cycle dumps the memory after the nbr_cycle ");
        my_printf("execution (if the round isn't already over) with the ");
        my_printf("following format: 32 bytes/line\nin hexadecimal (");
        my_printf("A0BCDEFE1DD3...)\n-n prog_number sets the next program's ");
        my_printf("number. By default, the first free number in the paramete");
        my_printf("r order\n-a load_address sets the next program's loading");
        my_printf("address. When no address is specified, optimize the");
        my_printf("addresses so that the processes are as far away from each");
        my_printf("other as possible. The addresses are MEM_SIZE modulo.");
        return true;
    }
    return false;
}

vm_t *init_vm(void)
{
    vm_t *vm = malloc(sizeof(vm_t));

    vm->nb_cycle = CYCLE_TO_DIE;
    vm->nb_champ = 2;
    vm->arene = init_arene();
    return vm;
}

int main (int ac, char **av)
{
    vm_t *vm = init_vm();
    if (usage(ac, av) )
        return 0;
    get_option(ac, av, vm);
    fill_champ(vm);
    my_printf("cycle to die : %i\nchampions :\n", vm->nb_cycle);
    for (int i = 0; vm->champ[i]; i++)
        my_printf("%i : %s -> %i\ncode :%s\n", vm->champ[i]->prog_nb, vm->champ[i]->name, vm->champ[i]->load_address, vm->champ[i]->buffer);
    my_printf("arena is :\n");
    for (int i = 0; i < NB_LINE; i++) {
        for (int j = 0; j < MEM_SIZE / NB_LINE; j++)
            my_printf("%s ", int_to_hexa_string(vm->arene[i][j]));
        my_printf("\n");
    }
    return 0;
}
