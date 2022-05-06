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

    struct vm_s {
        int nb_cycle;
    };

    bool get_option(char **av, vm_t *vm);

#endif
