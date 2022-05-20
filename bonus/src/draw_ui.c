/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** draw_ui
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"
#include "bonus.h"

int draw_text(char *text, sfVector3f pos, sfRenderWindow *window)
{
    sfText *score = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/zorque.ttf");

    if (!score)
        return EXIT_FAILURE;
    sfText_setColor(score, sfWhite);
    sfText_setString(score, text);
    sfText_setFont(score, font);
    sfText_setCharacterSize(score, pos.z);
    sfText_setPosition(score, (sfVector2f){pos.x, pos.y});
    sfRenderWindow_drawText(window, score, NULL);
    sfText_destroy(score);
    sfFont_destroy(font);
    return EXIT_SUCCESS;
}

char *conc(char *a, char *b)
{
    char *res = malloc(my_strlen(a) + my_strlen(b) + 1);
    int x = 0;

    if (!res)
        return NULL;
    for (int i = 0; i < my_strlen(a); i++, x++)
        res[x] = a[i];
    for (int i = 0; i < my_strlen(b); i++, x++)
        res[x] = b[i];
    res[x] = '\0';
    return res;
}

void draw_ui(vm_t *vm, sfRenderWindow *window, UNUSED sfEvent *event)
{
    sfFont *font = sfFont_createFromFile("assets/zorque.ttf");

    draw_text("Press Space to pause the vm", (sfVector3f){430, 620, 30},
                                                                    window);
    draw_text("Press S to speed up the vm", (sfVector3f){430, 670, 30},
                                                                    window);
    if (vm->speed == 0)
        draw_text("Speed : Max", (sfVector3f){430, 720, 30}, window);
    else
        draw_text(conc("Speed : ", inttochar(vm->speed)),
                                        (sfVector3f){430, 720, 30}, window);
    sfRenderWindow_display(window);
    sfFont_destroy(font);
}
