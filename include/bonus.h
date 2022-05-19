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

    void draw_arene(vm_t *vm, sfRenderWindow *window);
    bool handle_event(sfRenderWindow *window, sfEvent *event, vm_t *vm);
    void draw_ui(vm_t *vm, sfRenderWindow *window, sfEvent *event);
    void ftoa(float n, char *res, int afterpoint);
    int draw_text(char *text, sfVector3f pos, sfRenderWindow *window);

#endif