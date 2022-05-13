/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** write int in byte
*/

#include <stdio.h>
#include "writer.h"

unsigned int write_nbr(int nbr, char *filename, FILE *file)
{
    size_t err = 0;

    err = fwrite(&nbr, 1, sizeof(int), file);

    if (err != sizeof(int)) {
        return 84;
    }
    return 0;
}
