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

static char *process(champion_t *champ)
{
    int i = 0;

    for (; champ->prog[i]; i++);
    return inttochar(i);
}

static char *size(vm_t *vm, int nb)
{
    int oc = 0;

    for (int i = 0; i < NB_LINE; i++)
        for (int j = 0; j < IDX_MOD; j++)
            oc = (nb == vm->color[i][j]) ? oc + 1 : oc;
    return inttochar(oc);
}

static char *coverage(vm_t *vm, int nb)
{
    int oc = 0;
    char *ret;
    char *res;

    for (int i = 0; i < NB_LINE; i++)
        for (int j = 0; j < IDX_MOD; j++)
            oc = (nb == vm->color[i][j]) ? oc + 1 : oc;
    res = inttochar(oc * 100 / (NB_LINE * IDX_MOD));
    ret = malloc(my_strlen(res) + 3);
    for (int i = 0; res[i]; i++)
        ret[i] = res[i];
    ret[my_strlen(res)] = ' ';
    ret[my_strlen(res) + 1] = '%';
    ret[my_strlen(res) + 2] = '\0';
    return ret;

}

void text(vm_t *vm, sfRenderWindow *window)
{
    draw_text("Cycle : ", (sfVector3f){520, 510, 30}, window);
    draw_text(inttochar(vm->nb_cycle), (sfVector3f){670, 510, 30}, window);
    draw_text("Cycle to die : ", (sfVector3f){420, 550, 30}, window);
    draw_text(inttochar(vm->cycle_to_die), (sfVector3f){670, 550, 30}, window);
    draw_text(vm->champ[0]->name, (sfVector3f){30, 580, 20}, window);
    draw_text(vm->champ[1]->name, (sfVector3f){1000, 580, 20}, window);
    draw_text("ID :", (sfVector3f){30, 620, 20}, window);
    draw_text("ID :", (sfVector3f){1000, 620, 20}, window);
    draw_text(inttochar(vm->champ[0]->prog_nb), (sfVector3f){80, 620, 20}, window);
    draw_text(inttochar(vm->champ[1]->prog_nb), (sfVector3f){1050, 620, 20}, window);
    draw_text("Processes :", (sfVector3f){30, 660, 20}, window);
    draw_text("Processes :", (sfVector3f){1000, 660, 20}, window);
    draw_text(process(vm->champ[0]), (sfVector3f){180, 660, 20}, window);
    draw_text(process(vm->champ[1]), (sfVector3f){1150, 660, 20}, window);
    draw_text("Size :", (sfVector3f){30, 700, 20}, window);
    draw_text("Size :", (sfVector3f){1000, 700, 20}, window);
    draw_text(size(vm, 1), (sfVector3f){80, 700, 20}, window);
    draw_text(size(vm, 2), (sfVector3f){1050, 700, 20}, window);
    draw_text("Coverage :", (sfVector3f){30, 740, 20}, window);
    draw_text("Coverage :", (sfVector3f){1000, 740, 20}, window);
    draw_text(coverage(vm, 1), (sfVector3f){180, 740, 20}, window);
    draw_text(coverage(vm, 2), (sfVector3f){1150, 740, 20}, window);
}

void draw_pointers(vm_t *vm, sfRenderWindow *window)
{
    sfRectangleShape *pt = sfRectangleShape_create();
    int adress = 0;

    sfRectangleShape_setFillColor(pt, sfYellow);
    sfRectangleShape_setSize(pt, (sfVector2f){10, 10});
    for (int i = 0; vm->champ[i]; i++) {
        for (int j = 0; vm->champ[i]->prog[j] ; j++) {
            adress = (vm->champ[i]->prog[j]->coord.x + vm->champ[i]->prog[j]->coord.y * 512);
            vm->color[vm->champ[i]->prog[j]->coord.y][vm->champ[i]->prog[j]->coord.x] = i + 1;
            sfRectangleShape_setPosition(pt, (sfVector2f){30 + (adress % 128) * 10, 30 + (adress / 128) * 10});
            sfRenderWindow_drawRectangleShape(window, pt, NULL);
        }
    }
}

void draw_arene(vm_t *vm, sfRenderWindow *window)
{
    sfRectangleShape *red = sfRectangleShape_create();
    sfRectangleShape *grey = sfRectangleShape_create();
    sfRectangleShape *blue = sfRectangleShape_create();
    int adress = 0;
    sfRectangleShape_setFillColor(red, sfRed);
    sfRectangleShape_setFillColor(grey, sfBlack);
    sfRectangleShape_setFillColor(blue, sfBlue);
    sfRectangleShape_setSize(red, (sfVector2f){10, 10});
    sfRectangleShape_setSize(grey, (sfVector2f){10, 10});
    sfRectangleShape_setSize(blue, (sfVector2f){10, 10});

    sfRenderWindow_clear(window, sfWhite);
    for (int i = 0; i < NB_LINE; i++) {
        for (int j = 0; j < IDX_MOD; j++) {
            adress = (j + i * 512);
            if (vm->color[i][j] == 0) {
                sfRectangleShape_setPosition(grey, (sfVector2f){30 + (adress % 128) * 10, 30 + (adress / 128) * 10});
                sfRenderWindow_drawRectangleShape(window, grey, NULL);
            } else if (vm->color[i][j] == 1) {
                sfRectangleShape_setPosition(red, (sfVector2f){30 + (adress % 128) * 10, 30 + (adress / 128) * 10});
                sfRenderWindow_drawRectangleShape(window, red, NULL);
            } else {
                sfRectangleShape_setPosition(blue, (sfVector2f){30 + (adress % 128) * 10, 30 + (adress / 128) * 10});
                sfRenderWindow_drawRectangleShape(window, blue, NULL);
            }
        }
    }
    draw_pointers(vm, window);
    text(vm, window);
    sfRectangleShape_destroy(red);
    sfRectangleShape_destroy(grey);
    sfRectangleShape_destroy(blue);
}