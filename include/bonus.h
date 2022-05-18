/*
** EPITECH PROJECT, 2022
** corewar.c
** File description:
** corewar
*/

#ifndef BONUS
    # define BONUS

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>

    typedef struct type_button_s type_button_t;
    typedef struct button_s button_t;

    ////////////////////////////////////////////////////////////
    /// \brief Button aspect struct.
    ///
    /// Contain the texture, sprite, scale, rectangle, text, font, sound
    /// text position and the text size.
    ///
    /// \struct type_button_s type_button_t
    ///
    ////////////////////////////////////////////////////////////
    struct type_button_s {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f scale;
        sfIntRect rect;
        sfText *text;
        sfFont *font;
        sfMusic *sound;
        sfVector2f text_pos;
        int text_size;
    };

    ////////////////////////////////////////////////////////////
    /// \brief Button struct.
    ///
    /// Contain the base aspect, hoover aspect, clicked aspect, button position
    /// , action when hoover, action when clicked, x and y.
    ///
    /// \struct button_s button_t
    ///
    ////////////////////////////////////////////////////////////
    struct button_s {
        type_button_t *base;
        type_button_t *hoover;
        type_button_t *clicked;
        sfVector2f pos;
        int (*action_clicked)(vm_t *vm, ...);
        int (*action_hoover)(vm_t *vm, ...);
        int x;
        int y;
    };

    void draw_arene(vm_t *vm, sfRenderWindow *window);
    bool handle_event(sfRenderWindow *window, sfEvent *event, vm_t *vm);
    void draw_ui(vm_t *vm, sfRenderWindow *window, sfEvent *event);
    void ftoa(float n, char *res, int afterpoint);
    int draw_text(char *text, sfVector3f pos, sfRenderWindow *window);

#endif