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
#include "bonus.h"

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
    vm->color = init_arene();
    vm->pause = false;
    vm->speed = 10;
    return vm;
}

bool move_prog(prog_t *prog)
{
    if (prog->coord.x == 511 && prog->coord.y == 11)
        prog->coord = (coord_t){0, 0};
    else if (prog->coord.x == 511)
        prog->coord = (coord_t){0, prog->coord.y + 1};
    else
        prog->coord.x++;
    return true;
}

bool loop(vm_t *vm, sfRenderWindow *window, sfEvent *event)
{
    while (!win(vm)) {
        if (!vm->pause) {
            for (int i = 0; i < vm->nb_champ; i++) {
                actions(vm, vm->champ[i]);
            }
            vm->nb_cycle++;
        }
        draw_arene(vm, window);
        if (handle_event(window, event, vm))
            return true;
        draw_ui(vm, window, event);
    }
    return true;
}

int main(int ac, char **av)
{
    sfVideoMode mode = {1340, 880, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode,
                                                    "Corewar", sfClose, NULL);
    sfEvent event;
    vm_t *vm = init_vm();

    sfRenderWindow_setFramerateLimit(window, 0);
    if (usage(ac, av) )
        return 0;
    get_option(ac, av, vm);
    fill_champ(vm);
    loop(vm, window, &event);
    return 0;
}
