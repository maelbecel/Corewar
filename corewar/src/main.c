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
        my_printf("address. When no address type specified, optimize the ");
        my_printf("addresses so that the processes are as far away from each");
        my_printf("other as possible. The addresses are MEM_SIZE modulo.");
        return true;
    }
    return false;
}

vm_t *init_vm(void)
{
    vm_t *vm = malloc(sizeof(vm_t));

    vm->nb_cycle = 0;
    vm->cycle_to_die = CYCLE_TO_DIE;
    vm->arene = init_arene();
    return vm;
}

bool move_champs(champion_t *champ)
{
    for (int i = 0; champ->prog[i]; i++) {
        if (champ->prog[i]->coord.x == MEM_SIZE / NB_LINE - 1 &&
            champ->prog[i]->coord.y == NB_LINE - 1)
            champ->prog[i]->coord = (coord_t){0, 0};
        else if (champ->prog[i]->coord.x == MEM_SIZE / NB_LINE - 1)
            champ->prog[i]->coord = (coord_t){0, champ->prog[i]->coord.y + 1};
        else
            champ->prog[i]->coord.x++;
    }
    return true;
}

bool loop(vm_t *vm)
{
    while (!win(vm)) {
        for (int i = 0; i < vm->nb_champ; i++)
            actions(vm, vm->champ[i]);
        for (int i = 0; i < vm->nb_champ; i++)
            move_champs(vm->champ[i]);
        vm->nb_cycle++;
        printf("nb : %i\n", vm->nb_cycle);
    }
    return true;
}

void print_arene(vm_t *vm)
{
    my_printf("arena type :\n");
    for (int i = 0; i < NB_LINE; i++) {
        for (int j = 0; j < MEM_SIZE / NB_LINE; j++)
            my_printf((vm->arene[i][j] != 0) ? "\e[32m%s \e[0m": "%s ", int_to_hexa_string(vm->arene[i][j]));
        my_printf("\n");
    }
}

int main (int ac, char **av)
{
    vm_t *vm = init_vm();
    if (usage(ac, av) )
        return 0;
    get_option(ac, av, vm);
    fill_champ(vm);
    print_arene(vm);
    loop(vm);
    return 0;
}
