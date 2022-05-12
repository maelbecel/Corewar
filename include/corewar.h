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
    #include <sys/stat.h>
    #include "op.h"

    #define EXIT_ERROR 84

    typedef struct vm_s vm_t;
    typedef struct champion_s champion_t;
    typedef struct prog_s prog_t;
    typedef struct coord_s coord_t;

    struct vm_s {
        int nb_cycle;
        int nb_champ;
        unsigned char **arene;
        champion_t **champ;
    };

    struct champion_s {
        int prog_nb;
        int load_address;
        char *name;
        char *buffer;
        prog_t **prog;
    };

    struct coord_s {
        int x;
        int y;
    };

    struct prog_s {
        int reg[REG_NUMBER];
        coord_t coord;
        int goal_cycle;
        int current_cycle;
        int id_action;
        int carry;
    };

    bool get_option(int ac, char **av, vm_t *vm);
    bool check_cmp(vm_t *vm);
    int error(char *str);
    int init_champ(champion_t *champ);
    prog_t *init_prog(int load_ad, int prog_nb);
    unsigned char **init_arene(void);
    void *my_calloc(int size);
    char *int_to_hexa_string(int nb);
    char *get_data(champion_t *champ);
    bool fill_champ(vm_t *vm);
    bool actions(vm_t *vm, champion_t *champ);
    bool move_champs(champion_t *champ);


    void add(vm_t *vm, ...);
    void aff(vm_t *vm, ...);
    void and(vm_t *vm, ...);
    void a_fork(vm_t *vm, ...);
    void ld(vm_t *vm, ...);
    void ldi(vm_t *vm, ...);
    void lfork(vm_t *vm, ...);
    void live(vm_t *vm, ...);
    void lld(vm_t *vm, ...);
    void lldi(vm_t *vm, ...);
    void or(vm_t *vm, ...);
    void st(vm_t *vm, ...);
    void sti(vm_t *vm, ...);
    void sub(vm_t *vm, ...);
    void xor(vm_t *vm, ...);
    void zjmp(vm_t *vm, ...);

#endif
