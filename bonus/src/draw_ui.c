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

int do_nothing(UNUSED vm_t *vm, ...)
{
    return 0;
}

void draw_button(sfRenderWindow *window, button_t *button)
{
    sfSprite_setPosition(button->base->sprite, button->pos);
    sfText_setColor(button->base->text, sfBlack);
    sfText_setFont(button->base->text, button->base->font);
    sfText_setCharacterSize(button->base->text, button->base->text_size);
    sfText_setPosition(button->base->text,
        (sfVector2f){button->pos.x + button->base->text_pos.x,
                    button->pos.y + button->base->text_pos.y});
    sfSprite_setScale(button->base->sprite, button->base->scale);
    sfRenderWindow_drawSprite(window, button->base->sprite, NULL);
    sfRenderWindow_drawText(window, button->base->text, NULL);

}

void draw_hoover(sfRenderWindow *window, button_t *button)
{
    sfSprite_setPosition(button->hoover->sprite, button->pos);
    sfText_setColor(button->hoover->text, sfBlack);
    sfText_setFont(button->hoover->text, button->hoover->font);
    sfText_setCharacterSize(button->hoover->text, button->hoover->text_size);
    sfText_setPosition(button->hoover->text,
        (sfVector2f){button->pos.x + button->hoover->text_pos.x,
                    button->pos.y + button->hoover->text_pos.y});
    sfSprite_setScale(button->hoover->sprite, button->hoover->scale);
    sfRenderWindow_drawSprite(window, button->hoover->sprite, NULL);
    sfRenderWindow_drawText(window, button->hoover->text, NULL);
}

void draw_clicked(sfRenderWindow *window, button_t *button)
{
    sfSprite_setPosition(button->clicked->sprite, button->pos);
    sfText_setColor(button->clicked->text, sfBlack);
    sfText_setFont(button->clicked->text, button->clicked->font);
    sfText_setCharacterSize(button->clicked->text, button->clicked->text_size);
    sfText_setPosition(button->clicked->text,
        (sfVector2f){button->pos.x + button->clicked->text_pos.x,
                    button->pos.y + button->clicked->text_pos.y});
    sfSprite_setScale(button->clicked->sprite, button->clicked->scale);
    sfRenderWindow_drawSprite(window, button->clicked->sprite, NULL);
    sfRenderWindow_drawText(window, button->clicked->text, NULL);
}

int draw_text(char *text, sfVector3f pos, sfRenderWindow *window)
{
    sfText *score = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/zorque.ttf");

    if (!score)
        return EXIT_FAILURE;
    sfText_setColor(score, sfBlack);
    sfText_setString(score, text);
    sfText_setFont(score, font);
    sfText_setCharacterSize(score, pos.z);
    sfText_setPosition(score, (sfVector2f){pos.x, pos.y});
    sfRenderWindow_drawText(window, score, NULL);
    sfText_destroy(score);
    sfFont_destroy(font);
    return EXIT_SUCCESS;
}

int is_hoover(button_t *button, sfRenderWindow *window, vm_t *vm)
{
    sfVector2f pos = button->pos;
    sfVector2f scale = button->base->scale;
    sfVector2u size = sfTexture_getSize(
                                button->hoover->texture);
    sfVector2i click = sfMouse_getPositionRenderWindow(window);

    size.x *= scale.x;
    size.y *= scale.y;
    if (click.x > pos.x && click.x < (pos.x + size.x)) {
        if (click.y > pos.y && click.y < (pos.y + size.y)) {
            button->action_hoover(vm);
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int is_click(button_t *button, sfRenderWindow *window, vm_t *vm)
{
    if (!is_hoover(button, window, vm) || !sfRenderWindow_isOpen(window)) {
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

type_button_t *init_button_type(char *text, char *texture, sfVector2i size)
{
    type_button_t *type = malloc(sizeof(type_button_t));

    if (!type || !(type->texture = sfTexture_createFromFile(texture, NULL)))
        return NULL;
    if (!(type->sprite = sfSprite_create()))
        return NULL;
    type->scale = (sfVector2f) {1, 1};
    type->rect = (sfIntRect){0, 0, size.x, size.y};
    if (!(type->text = sfText_create()))
        return NULL;
    if (!(type->font = sfFont_createFromFile("assets/zorque.ttf")))
        return NULL;
    type->text_size = 30;
    type->text_pos = (sfVector2f){(30), (30)};
    type->sound = NULL;
    sfText_setString(type->text, text);
    sfSprite_setTexture(type->sprite, type->texture, sfTrue);
    return type;
}

button_t *init_button(char *text, char *texture,
                    sfVector2f pos, sfVector2i size)
{
    button_t *button = malloc(sizeof(button_t));

    if (!button)
        return NULL;
    if (!(button->base = init_button_type(text, texture, size)))
        return NULL;
    if (!(button->hoover = init_button_type(text,
                                            "assets/button1_hoover.png", size)))
        return NULL;
    if (!(button->clicked = init_button_type(text,
                                            "assets/button1_clicked.png", size)))
        return NULL;
    button->pos.x = pos.x;
    button->pos.y = pos.y;
    button->action_clicked = do_nothing;
    button->action_hoover = do_nothing;
    return button;
}

button_t **init_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 2);

    // buttons[0] = init_button("pause", "assets/button1.png",
    //                             (sfVector2f){500, 600}, (sfVector2i){792, 206});
    // buttons[0]->base->scale = (sfVector2f){0.5, 0.4};
    // buttons[0]->hoover->scale = (sfVector2f){0.5, 0.4};
    // buttons[0]->clicked->scale = (sfVector2f){0.5, 0.4};
    // buttons[0]->action_clicked = pause_vm;
    buttons[0] = NULL;
    buttons[1] = NULL;
    return buttons;
}

void draw_ui(vm_t *vm, sfRenderWindow *window, sfEvent *event)
{
    button_t **buttons = init_buttons();
    sfFont *font = sfFont_createFromFile("assets/zorque.ttf");

    for (int i = 0; buttons[i] != NULL; i++) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(buttons[i], window, vm)) {
            draw_clicked(window, buttons[i]);
            buttons[i]->action_clicked(vm);
        } else if (is_hoover(buttons[i], window, vm))
            draw_hoover(window, buttons[i]);
        else
            draw_button(window, buttons[i]);
    }
    draw_text("Press Space to pause the vm", (sfVector3f){430, 620, 30},
                                                                    window);
    sfRenderWindow_display(window);
    sfFont_destroy(font);
}
