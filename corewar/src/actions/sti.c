/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** action
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

void sti_rr(vm_t *vm, prog_t *prog)
{
    (void)vm;
    (void)prog;
    printf("sti rr\n");
}

void sti_nn(vm_t *vm, prog_t *prog)
{
    move_prog(prog);
    int reg = get_param(vm, prog->coord, 1);
    move_prog(prog);
    int nb1 = get_param(vm, prog->coord, 2);
    move_prog(prog);
    move_prog(prog);
    int nb2 = get_param(vm, prog->coord, 2);
    move_prog(prog);
    move_prog(prog);
    int adress = (prog->coord.y * IDX_MOD + prog->coord.x + nb1 + nb2 - 7);
    vm->arene[adress / IDX_MOD][adress % IDX_MOD] = prog->reg[reg - 1];
    printf("sti r%i, %i, %i -> (%i, %i) = %i\n", reg, nb1, nb2, adress / IDX_MOD, adress % IDX_MOD, prog->reg[reg - 1]);
}

void sti_rn(vm_t *vm, prog_t *prog)
{
    (void)vm;
    (void)prog;
    printf("sti rn\n");
}

void sti_nr(vm_t *vm, prog_t *prog)
{
    (void)vm;
    (void)prog;
    printf("sti nr\n");
}

void sti(vm_t *vm, ...)
{
    va_list arg;
    va_start(arg, vm);
    UNUSED champion_t *champ = va_arg(arg, champion_t *);
    prog_t *prog = va_arg(arg, prog_t *);
    va_end(arg);
    move_prog(prog);
    switch (get_param(vm, prog->coord, 1)) {
        case STI_RR: sti_rr(vm, prog);
            break;
        case STI_NN: sti_nn(vm, prog);
            break;
        case STI_RN: sti_rn(vm, prog);
            break;
        case STI_NR: sti_nr(vm, prog);
            break;
        default: error("sti: unknown instruction");
    }
}

/*
    si 2 registre : 54 r1 r2
    si 2 nombres : 68 n1n1 n2n2
    si 1 registre et 1 nombre : 58 r1 n1n1
    si 1 nombre et 1 registre : 64 n1n1 r1
*/