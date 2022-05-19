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

int handle_speed(sfRenderWindow *window, vm_t *vm)
{
    if (vm->speed == 0)
        vm->speed = 10;
    else if (vm->speed < 160)
        vm->speed *= 2;
    else
        vm->speed = 0;
    sfRenderWindow_setFramerateLimit(window, vm->speed);
    return 0;
}

bool handle_event(sfRenderWindow *window, sfEvent *event, vm_t *vm)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            return true;
        if (event->type == sfEvtKeyPressed && event->key.code == sfKeySpace)
            pause_vm(vm);
        if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape)
            return true;
        if (event->type == sfEvtKeyPressed && event->key.code == sfKeyS)
            handle_speed(window, vm);
    }
    return false;
}