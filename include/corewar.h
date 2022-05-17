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
    #define ACT_CASE(vm, x, y) vm->arene[y][x]

    #define STI_RR 0x54
    #define STI_NN 0x68
    #define STI_RN 0x58
    #define STI_NR 0x64

    #define AND_NN 0xa4
    #define AND_NA 0xb4
    #define AND_AR 0xd4
    #define AND_AN 0xe4
    #define AND_AA 0xf4
    #define AND_RR 0x54
    #define AND_RN 0x64
    #define AND_RA 0x74
    #define AND_NR 0x94

    #define LDI_AN 0xe4
    #define LDI_NN 0xa4
    #define LDI_AR 0xd4
    #define LDI_RR 0x54
    #define LDI_RN 0x64

    typedef struct vm_s vm_t;
    typedef struct champion_s champion_t;
    typedef struct prog_s prog_t;
    typedef struct coord_s coord_t;
    typedef struct codaction_s codaction_t;
    typedef int CODE;

    struct codaction_s {
        CODE code;
        void (*action)(prog_t *prog, vm_t *vm);
    };

    struct vm_s {
        int nb_cycle;
        int cycle_to_die;
        int nb_champ;
        unsigned char **arene;
        champion_t **champ;
    };

    struct champion_s {
        int prog_nb;
        int load_address;
        bool live;
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
    bool move_prog(prog_t *prog);
    bool win(vm_t *vm);
    int int_from_byte(vm_t *vm, coord_t coord);
    size_t get_param(vm_t *vm, coord_t coord, size_t size);
    void print_arene(vm_t *vm);
    bool verif_champ(vm_t *vm);
    int endian(int nb);

    void ldi_ar(vm_t *vm, prog_t *prog);
    void ldi_an(vm_t *vm, prog_t *prog);
    void ldi_rr(vm_t *vm, prog_t *prog);
    void ldi_rn(vm_t *vm, prog_t *prog);
    void ldi_nn(vm_t *vm, prog_t *prog);
    void lldi_ar(vm_t *vm, prog_t *prog);
    void lldi_an(vm_t *vm, prog_t *prog);
    void lldi_rr(vm_t *vm, prog_t *prog);
    void lldi_rn(vm_t *vm, prog_t *prog);
    void lldi_nn(vm_t *vm, prog_t *prog);

    void and_nn(prog_t *prog, vm_t *vm);
    void and_rr(prog_t *prog, vm_t *vm);
    void and_nr(prog_t *prog, vm_t *vm);
    void and_rn(prog_t *prog, vm_t *vm);
    void and_an(prog_t *prog, vm_t *vm);
    void and_aa(prog_t *prog, vm_t *vm);
    void and_na(prog_t *prog, vm_t *vm);
    void and_ar(prog_t *prog, vm_t *vm);
    void and_ra(prog_t *prog, vm_t *vm);

    void or_nn(prog_t *prog, vm_t *vm);
    void or_rr(prog_t *prog, vm_t *vm);
    void or_nr(prog_t *prog, vm_t *vm);
    void or_rn(prog_t *prog, vm_t *vm);
    void or_an(prog_t *prog, vm_t *vm);
    void or_aa(prog_t *prog, vm_t *vm);
    void or_na(prog_t *prog, vm_t *vm);
    void or_ar(prog_t *prog, vm_t *vm);
    void or_ra(prog_t *prog, vm_t *vm);

    void xor_nn(prog_t *prog, vm_t *vm);
    void xor_rr(prog_t *prog, vm_t *vm);
    void xor_nr(prog_t *prog, vm_t *vm);
    void xor_rn(prog_t *prog, vm_t *vm);
    void xor_an(prog_t *prog, vm_t *vm);
    void xor_aa(prog_t *prog, vm_t *vm);
    void xor_na(prog_t *prog, vm_t *vm);
    void xor_ar(prog_t *prog, vm_t *vm);
    void xor_ra(prog_t *prog, vm_t *vm);

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
