/*
** EPITECH PROJECT, 2022
** corewar.c
** File description:
** corewar
*/

#ifndef COREWAR_H_
    #define COREWAR_H_

    ////////////////////////////////////////////////////////////
    /// \brief Usefull libraries
    ////////////////////////////////////////////////////////////
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include "op.h"

    ////////////////////////////////////////////////////////////
    /// \brief Exit error code
    ////////////////////////////////////////////////////////////
    #define EXIT_ERROR 84

    ////////////////////////////////////////////////////////////
    /// \brief Catch the actual case
    ////////////////////////////////////////////////////////////
    #define ACT_CASE(vm, x, y) vm->arene[y][x]

    ////////////////////////////////////////////////////////////
    /// \brief Code for 2 register in sti
    ////////////////////////////////////////////////////////////
    #define STI_RR 0x54

    ////////////////////////////////////////////////////////////
    /// \brief Code for 2 numbers in sti
    ////////////////////////////////////////////////////////////
    #define STI_NN 0x68

    ////////////////////////////////////////////////////////////
    /// \brief Code for 1 register and 1 number in sti
    ////////////////////////////////////////////////////////////
    #define STI_RN 0x58

    ////////////////////////////////////////////////////////////
    /// \brief Code for 1 number and 1 register in sti
    ////////////////////////////////////////////////////////////
    #define STI_NR 0x64

    ////////////////////////////////////////////////////////////
    /// \brief Code for 2 numbers in and
    ////////////////////////////////////////////////////////////
    #define AND_NN 0xa4

    ////////////////////////////////////////////////////////////
    /// \brief Code for 1 number and 1 adress in sti
    ////////////////////////////////////////////////////////////
    #define AND_NA 0xb4

    ////////////////////////////////////////////////////////////
    /// \brief Code for 1 adress and 1 register in sti
    ////////////////////////////////////////////////////////////
    #define AND_AR 0xd4

    ////////////////////////////////////////////////////////////
    /// \brief Code for 1 adress and 1 number in sti
    ////////////////////////////////////////////////////////////
    #define AND_AN 0xe4

    ////////////////////////////////////////////////////////////
    /// \brief Code for 2 adresses in sti
    ////////////////////////////////////////////////////////////
    #define AND_AA 0xf4

    ////////////////////////////////////////////////////////////
    /// \brief Code for 2 registers in sti
    ////////////////////////////////////////////////////////////
    #define AND_RR 0x54

    ////////////////////////////////////////////////////////////
    /// \brief Code for 1 register and 1 number in sti
    ////////////////////////////////////////////////////////////
    #define AND_RN 0x64

    ////////////////////////////////////////////////////////////
    /// \brief Code for 1 register and 1 adress in sti
    ////////////////////////////////////////////////////////////
    #define AND_RA 0x74

    ////////////////////////////////////////////////////////////
    /// \brief Code for 1 number and 1 register in sti
    ////////////////////////////////////////////////////////////
    #define AND_NR 0x94

    ////////////////////////////////////////////////////////////
    /// \brief Code for 1 adress and 1 number in ldi
    ////////////////////////////////////////////////////////////
    #define LDI_AN 0xe4

    ////////////////////////////////////////////////////////////
    /// \brief Code for 2 numbers in ldi
    ////////////////////////////////////////////////////////////
    #define LDI_NN 0xa4

    ////////////////////////////////////////////////////////////
    /// \brief Code for 1 adress and 1 register in ldi
    ////////////////////////////////////////////////////////////
    #define LDI_AR 0xd4

    ////////////////////////////////////////////////////////////
    /// \brief Code for 2 registers in ldi
    ////////////////////////////////////////////////////////////
    #define LDI_RR 0x54

    ////////////////////////////////////////////////////////////
    /// \brief Code for 1 register and 1 number in ldi
    ////////////////////////////////////////////////////////////
    #define LDI_RN 0x64

    ////////////////////////////////////////////////////////////
    /// \brief Usefull structures
    ////////////////////////////////////////////////////////////
    typedef struct vm_s vm_t;
    typedef struct champion_s champion_t;
    typedef struct prog_s prog_t;
    typedef struct coord_s coord_t;
    typedef struct codaction_s codaction_t;

    ////////////////////////////////////////////////////////////
    /// \brief Rename int for CODE
    ////////////////////////////////////////////////////////////
    typedef int CODE;

    ////////////////////////////////////////////////////////////
    /// \brief Structure to give an action to a code
    ////////////////////////////////////////////////////////////
    struct codaction_s {
        CODE code;
        void (*action)(prog_t *prog, vm_t *vm);
    };

    ////////////////////////////////////////////////////////////
    /// \brief Structure to handle virtual machine
    ////////////////////////////////////////////////////////////
    struct vm_s {
        bool pause;
        int speed;
        int nb_cycle;
        int cycle_to_die;
        int nb_champ;
        unsigned char **arene;
        unsigned char **color;
        champion_t **champ;
    };

    ////////////////////////////////////////////////////////////
    /// \brief Structure to stock all data of a champion
    ////////////////////////////////////////////////////////////
    struct champion_s {
        int prog_nb;
        int load_address;
        bool live;
        char *name;
        char *buffer;
        prog_t **prog;
    };

    ////////////////////////////////////////////////////////////
    /// \brief Tuple of coordinates
    ////////////////////////////////////////////////////////////
    struct coord_s {
        int x;
        int y;
    };

    ////////////////////////////////////////////////////////////
    /// \brief Structure to stock all data of a process
    ////////////////////////////////////////////////////////////
    struct prog_s {
        int reg[REG_NUMBER];
        coord_t coord;
        int goal_cycle;
        int current_cycle;
        int id_action;
        int carry;
    };

    ////////////////////////////////////////////////////////////
    /// \brief Function to exit in error case
    ///
    /// \param str Error message
    ///
    /// \return EXIT_ERROR
    ////////////////////////////////////////////////////////////
    int error(char *str);

    ////////////////////////////////////////////////////////////
    /// \brief Init a champion
    ///
    /// \param champ Champion to init
    ///
    /// \return 0 if success, -1 otherwise
    ////////////////////////////////////////////////////////////
    int init_champ(champion_t *champ);

    ////////////////////////////////////////////////////////////
    /// \brief Change the endian of an number
    ///
    /// \param nb Number to update
    ///
    /// \return Endian changed version of the number
    ////////////////////////////////////////////////////////////
    int endian(int nb);

    ////////////////////////////////////////////////////////////
    /// \brief Read an int on 4 bytes
    ///
    /// \param vm Virtual machine
    /// \param coord Coordinate to start to read
    ///
    /// \return Int read from the \a coord
    ////////////////////////////////////////////////////////////
    int int_from_byte(vm_t *vm, coord_t coord);

    ////////////////////////////////////////////////////////////
    /// \brief Display the arena
    ///
    /// \param vm Virtual machine
    ////////////////////////////////////////////////////////////
    void print_arene(vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief Get all options
    ///
    /// \param ac Number of arguments
    /// \param av Arguments
    /// \param vm Virtual machine
    ///
    /// \return true
    ////////////////////////////////////////////////////////////
    bool get_option(int ac, char **av, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief Check champion options
    ///
    /// \param vm Virtual machine
    ///
    /// \return true
    ////////////////////////////////////////////////////////////
    bool check_cmp(vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief Fill champion options
    ///
    /// \param vm Virtual machine
    ///
    /// \return true
    ////////////////////////////////////////////////////////////
    bool fill_champ(vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief Do action of champion
    ///
    /// \param vm Virtual machine
    /// \param champ champ to execute
    ///
    /// \return true
    ////////////////////////////////////////////////////////////
    bool actions(vm_t *vm, champion_t *champ);

    ////////////////////////////////////////////////////////////
    /// \brief Move process to next case in memory
    ///
    /// \param prog process to move
    ///
    /// \return true
    ////////////////////////////////////////////////////////////
    bool move_prog(prog_t *prog);

    ////////////////////////////////////////////////////////////
    /// \brief Check win condition
    ///
    /// \param vm Virtual machine
    ///
    /// \return true if success, false otherwise
    ////////////////////////////////////////////////////////////
    bool win(vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief Verif if champions options are valid
    ///
    /// \param vm Virtual machine
    ///
    /// \return true
    ////////////////////////////////////////////////////////////
    bool verif_champ(vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief Turn an int into an hexadecimal string
    ///
    /// \param nb int to convert
    ///
    /// \return string of \a nb in hexadecimal representation
    ////////////////////////////////////////////////////////////
    char *int_to_hexa_string(int nb);

    ////////////////////////////////////////////////////////////
    /// \brief Fill buffer of a champion
    ///
    /// \param champ Champion to fill
    ///
    /// \return buffer read
    ////////////////////////////////////////////////////////////
    char *get_data(champion_t *champ);

    ////////////////////////////////////////////////////////////
    /// \brief Alloc and memset a memory zone
    ///
    /// \param size Size of the zone
    ///
    /// \return Memory zone calloc
    ////////////////////////////////////////////////////////////
    void *my_calloc(int size);

    ////////////////////////////////////////////////////////////
    /// \brief Get parameter
    ///
    /// \param vm Virtual machine
    /// \param coord Coordinate where start to read parameter
    /// \param size Size of the parameter
    ///
    /// \return parameter read
    ////////////////////////////////////////////////////////////
    size_t get_param(vm_t *vm, coord_t coord, size_t size);

    ////////////////////////////////////////////////////////////
    /// \brief Init a process
    ///
    /// \param load_ad Adress to load the process
    /// \param prog_nb Number of the process
    ///
    /// \return Process init
    ////////////////////////////////////////////////////////////
    prog_t *init_prog(int load_ad, int prog_nb);

    ////////////////////////////////////////////////////////////
    /// \brief Init the arena
    ///
    /// \return Arena init
    ////////////////////////////////////////////////////////////
    unsigned char **init_arene(void);

    ////////////////////////////////////////////////////////////
    /// \brief LDI action with 1 adress and 1 register
    ///
    /// \param vm Virtual machine
    /// \param prog Actual process
    ///
    ////////////////////////////////////////////////////////////
    void ldi_ar(vm_t *vm, prog_t *prog);

    ////////////////////////////////////////////////////////////
    /// \brief LDI action with 1 adress and 1 number
    ///
    /// \param vm Virtual machine
    /// \param prog Actual process
    ///
    ////////////////////////////////////////////////////////////
    void ldi_an(vm_t *vm, prog_t *prog);

    ////////////////////////////////////////////////////////////
    /// \brief LDI action with 2 registers
    ///
    /// \param vm Virtual machine
    /// \param prog Actual process
    ///
    ////////////////////////////////////////////////////////////
    void ldi_rr(vm_t *vm, prog_t *prog);

    ////////////////////////////////////////////////////////////
    /// \brief LDI action with 1 register and 1 number
    ///
    /// \param vm Virtual machine
    /// \param prog Actual process
    ///
    ////////////////////////////////////////////////////////////
    void ldi_rn(vm_t *vm, prog_t *prog);

    ////////////////////////////////////////////////////////////
    /// \brief LDI action with 2 numbers
    ///
    /// \param vm Virtual machine
    /// \param prog Actual process
    ///
    ////////////////////////////////////////////////////////////
    void ldi_nn(vm_t *vm, prog_t *prog);

    ////////////////////////////////////////////////////////////
    /// \brief LLDI action with 1 adress and 1 register
    ///
    /// \param vm Virtual machine
    /// \param prog Actual process
    ///
    ////////////////////////////////////////////////////////////
    void lldi_ar(vm_t *vm, prog_t *prog);

    ////////////////////////////////////////////////////////////
    /// \brief LLDI action with 1 adress and 1 number
    ///
    /// \param vm Virtual machine
    /// \param prog Actual process
    ///
    ////////////////////////////////////////////////////////////
    void lldi_an(vm_t *vm, prog_t *prog);

    ////////////////////////////////////////////////////////////
    /// \brief LLDI action with 2 registers
    ///
    /// \param vm Virtual machine
    /// \param prog Actual process
    ///
    ////////////////////////////////////////////////////////////
    void lldi_rr(vm_t *vm, prog_t *prog);

    ////////////////////////////////////////////////////////////
    /// \brief LLDI action with 1 register and 1 number
    ///
    /// \param vm Virtual machine
    /// \param prog Actual process
    ///
    ////////////////////////////////////////////////////////////
    void lldi_rn(vm_t *vm, prog_t *prog);

    ////////////////////////////////////////////////////////////
    /// \brief LLDI action with 2 numbers
    ///
    /// \param vm Virtual machine
    /// \param prog Actual process
    ///
    ////////////////////////////////////////////////////////////
    void lldi_nn(vm_t *vm, prog_t *prog);

    ////////////////////////////////////////////////////////////
    /// \brief AND action with 2 numbers
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void and_nn(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief AND action with 2 registers
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void and_rr(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief AND action with 1 number and 1 register
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void and_nr(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief AND action with 1 register and 1 number
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void and_rn(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief AND action with 1 adress and 1 number
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void and_an(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief AND action with 2 adresses
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void and_aa(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief AND action with 1 number and 1 adress
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void and_na(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief AND action with 1 adress and 1 register
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void and_ar(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief AND action with 1 register and 1 adress
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void and_ra(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief OR action with 2 numbers
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void or_nn(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief OR action with 2 registers
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void or_rr(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief OR action with 1 number and 1 register
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void or_nr(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief OR action with 1 register and 1 number
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void or_rn(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief OR action with 1 adress and 1 number
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void or_an(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief OR action with 2 adresses
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void or_aa(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief OR action with 1 number and 1 adress
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void or_na(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief OR action with 1 adress and 1 register
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void or_ar(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief OR action with 1 register and 1 adress
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void or_ra(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief XOR action with 2 numbers
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void xor_nn(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief XOR action with 2 registers
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void xor_rr(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief XOR action with 1 number and 1 register
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void xor_nr(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief XOR action with 1 register and 1 number
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void xor_rn(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief XOR action with 1 adress and 1 number
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void xor_an(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief XOR action with 2 adresses
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void xor_aa(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief XOR action with 1 number and 1 adress
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void xor_na(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief XOR action with 1 adress and 1 register
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void xor_ar(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief XOR action with 1 register and 1 adress
    ///
    /// \param prog Actual process
    /// \param vm Virtual machine
    ///
    ////////////////////////////////////////////////////////////
    void xor_ra(prog_t *prog, vm_t *vm);

    ////////////////////////////////////////////////////////////
    /// \brief Do the ADD action
    ///
    /// \param vm Virtual machine
    /// \param ...Other usefull arguments
    ///
    ////////////////////////////////////////////////////////////
    void add(vm_t *vm, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Do the AFF action
    ///
    /// \param vm Virtual machine
    /// \param ...Other usefull arguments
    ///
    ////////////////////////////////////////////////////////////
    void aff(vm_t *vm, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Do the AND action
    ///
    /// \param vm Virtual machine
    /// \param ...Other usefull arguments
    ///
    ////////////////////////////////////////////////////////////
    void and(vm_t *vm, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Do the FORK action
    ///
    /// \param vm Virtual machine
    /// \param ...Other usefull arguments
    ///
    ////////////////////////////////////////////////////////////
    void a_fork(vm_t *vm, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Do the LD action
    ///
    /// \param vm Virtual machine
    /// \param ...Other usefull arguments
    ///
    ////////////////////////////////////////////////////////////
    void ld(vm_t *vm, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Do the LDI action
    ///
    /// \param vm Virtual machine
    /// \param ...Other usefull arguments
    ///
    ////////////////////////////////////////////////////////////
    void ldi(vm_t *vm, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Do the LFORK action
    ///
    /// \param vm Virtual machine
    /// \param ...Other usefull arguments
    ///
    ////////////////////////////////////////////////////////////
    void lfork(vm_t *vm, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Do the LIVE action
    ///
    /// \param vm Virtual machine
    /// \param ...Other usefull arguments
    ///
    ////////////////////////////////////////////////////////////
    void live(vm_t *vm, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Do the LLD action
    ///
    /// \param vm Virtual machine
    /// \param ...Other usefull arguments
    ///
    ////////////////////////////////////////////////////////////
    void lld(vm_t *vm, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Do the LLDI action
    ///
    /// \param vm Virtual machine
    /// \param ...Other usefull arguments
    ///
    ////////////////////////////////////////////////////////////
    void lldi(vm_t *vm, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Do the OR action
    ///
    /// \param vm Virtual machine
    /// \param ...Other usefull arguments
    ///
    ////////////////////////////////////////////////////////////
    void or(vm_t *vm, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Do the ST action
    ///
    /// \param vm Virtual machine
    /// \param ...Other usefull arguments
    ///
    ////////////////////////////////////////////////////////////
    void st(vm_t *vm, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Do the STI action
    ///
    /// \param vm Virtual machine
    /// \param ...Other usefull arguments
    ///
    ////////////////////////////////////////////////////////////
    void sti(vm_t *vm, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Do the SUB action
    ///
    /// \param vm Virtual machine
    /// \param ...Other usefull arguments
    ///
    ////////////////////////////////////////////////////////////
    void sub(vm_t *vm, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Do the XOR action
    ///
    /// \param vm Virtual machine
    /// \param ...Other usefull arguments
    ///
    ////////////////////////////////////////////////////////////
    void xor(vm_t *vm, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Do the ZJMP action
    ///
    /// \param vm Virtual machine
    /// \param ...Other usefull arguments
    ///
    ////////////////////////////////////////////////////////////
    void zjmp(vm_t *vm, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Get the name of the champ
    ///
    /// \param name path to the champ
    ///
    /// \return name of the champ
    ////////////////////////////////////////////////////////////
    char *getname(char *name);

    ////////////////////////////////////////////////////////////
    /// \brief Delete a process
    ///
    /// \param champ Actual champion
    /// \param i process id
    ///
    /// \return True
    ///
    ////////////////////////////////////////////////////////////
    bool del_prog(champion_t *champ, int i);

#endif
