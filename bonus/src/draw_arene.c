/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "bonus.h"
#include "op.h"

void draw_pointers(vm_t *vm, sfRenderWindow *window)
{
    sfRectangleShape *pt = sfRectangleShape_create();
    int adress = 0;

    sfRectangleShape_setFillColor(pt, sfYellow);
    sfRectangleShape_setSize(pt, (sfVector2f){10, 10});
    for (int i = 0; vm->champ[i]; i++) {
        for (int j = 0; vm->champ[i]->prog[j] ; j++) {
            adress = (vm->champ[i]->prog[j]->coord.x + vm->champ[i]->prog[j]->coord.y * 128);
            sfRectangleShape_setPosition(pt, (sfVector2f){30 + (adress % 128) * 10, 30 + (adress / 128) * 10});
            printf("adress = line %i, column %i\n", adress / 128, adress % 128);
            sfRenderWindow_drawRectangleShape(window, pt, NULL);
        }
    }
}

void draw_arene(UNUSED vm_t *vm, sfRenderWindow *window)
{
    sfRectangleShape *red = sfRectangleShape_create();
    sfRectangleShape *grey = sfRectangleShape_create();
    sfRectangleShape *blue = sfRectangleShape_create();
    sfRectangleShape_setFillColor(red, sfRed);
    sfRectangleShape_setFillColor(grey, sfBlack);
    sfRectangleShape_setFillColor(blue, sfBlue);
    sfRectangleShape_setSize(red, (sfVector2f){10, 10});
    sfRectangleShape_setSize(grey, (sfVector2f){10, 10});
    sfRectangleShape_setSize(blue, (sfVector2f){10, 10});

    sfRenderWindow_clear(window, sfWhite);
    for (int i = 0; i < 48; i++)
        for (int j = 0; j < 128; j++) {
            sfRectangleShape_setPosition(red, (sfVector2f){30 + j * 10, 30 + i * 10});
            sfRenderWindow_drawRectangleShape(window, red, NULL);
        }

    draw_pointers(vm, window);
    sfRenderWindow_display(window);
    sfRectangleShape_destroy(red);
    sfRectangleShape_destroy(grey);
    sfRectangleShape_destroy(blue);
}