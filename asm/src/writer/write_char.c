/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** write char in byte
*/

#include <stdio.h>
#include "writer.h"

unsigned int write_char(char c, char *filename, FILE *file)
{
    size_t err = 0;

    err = fwrite(&c, 1, sizeof(char), file);
    if (err != sizeof(char)) {
        return 84;
    }
    return 0;
}
