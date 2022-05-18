/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** event
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"
#include "bonus.h"

int pause_vm(vm_t *vm)
{
    if (vm->pause)
        vm->pause = false;
    else
        vm->pause = true;
    return 0;
}

bool handle_event(sfRenderWindow *window, sfEvent *event, vm_t *vm)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed) {
            return true;
        }
        if (event->type == sfEvtKeyPressed && event->key.code == sfKeySpace)
            pause_vm(vm);
    }
    return false;
}