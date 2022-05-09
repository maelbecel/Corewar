/*
** EPITECH PROJECT, 2022
** corewar.c
** File description:
** corewar
*/

#ifndef COREWAR_H_
    #define COREWAR_H_

    #include <stdbool.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>

    #define EXIT_ERROR 84

    typedef struct vm_s vm_t;
    typedef struct champion_s champion_t;
    typedef struct prog_s prog_t;

    struct vm_s {
        int nb_cycle;
        champion_t **champions;
    };

    struct champion_s {
        int prog_nb;
        int load_address;
        char *name;
        prog_t *prog;
    };

    struct prog_s {
        int *reg;
        int pc;
        int carry;
    };

    bool get_option(int ac, char **av, vm_t *vm);
    bool check_cmp(vm_t *vm);
    int error(char *str);

#endif
