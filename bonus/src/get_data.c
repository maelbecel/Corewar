/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** get_data
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"

char *get_data(champion_t *champ)
{
    int fd = open(champ->name, O_RDONLY);
    struct stat file;

    if (fd == -1)
        error("Can't open file\n");
    if (stat(champ->name, &file) == -1)
        return NULL;
    champ->buffer = malloc(sizeof(unsigned char) * file.st_size);
    if (!champ->buffer)
        return NULL;
    read(fd, champ->buffer, file.st_size);
    close(fd);
    return champ->buffer;
}