/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

static void usage(void)
{
    my_printf("USAGE\n./corewar [-dump nbr_cycle] [[-n prog_number] ");
    my_printf("[-a load_address] prog_name] ...\nDESCRIPTION\n");
    my_printf("-dump nbr_cycle dumps the memory after the nbr_cycle ");
    my_printf("execution (if the round isn't\nalready over) with the ");
    my_printf("following format: 32 bytes/line\nin hexadecimal (");
    my_printf("A0BCDEFE1DD3...)\n-n prog_number sets the next program's ");
    my_printf("number. By default, the first free number\nin the parameter ");
    my_printf("order\n-a load_address sets the next program's loading");
    my_printf("address. When no address is\nspecified, optimize the");
    my_printf("addresses so that the processes are as far\naway from each");
    my_printf("other as possible. The addresses are MEM_SIZE modulo.\n");
}

int main (int ac, char **av, UNUSED char **env)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        usage();
    return EXIT_SUCCESS;
}
