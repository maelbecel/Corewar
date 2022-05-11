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
    #include "op.h"

    #define EXIT_ERROR 84

    typedef struct vm_s vm_t;
    typedef struct champion_s champion_t;
    typedef struct prog_s prog_t;
    typedef struct coord_s coord_t;

    struct vm_s {
        int nb_cycle;
        int nb_champ;
        champion_t **champ;
    };

    struct champion_s {
        int prog_nb;
        int load_address;
        char *name;
        prog_t *prog;
    };

    struct prog_s {
        int reg[REG_NUMBER];
        coord_t coord;
        int goal_cycle;
        int current_cycle;
        int id_action;
        int carry;
    };

    struct coord_s {
        int x;
        int y;
    };

    bool get_option(int ac, char **av, vm_t *vm);
    bool check_cmp(vm_t *vm);
    int error(char *str);
    champion_t **init_champ(vm_t *vm);
    prog_t *init_prog(int load_ad, int prog_nb);

#endif
