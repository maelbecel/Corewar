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

bool handle_event(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed) {
            return true;
        }
    }
    return false;
}