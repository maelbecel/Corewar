/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** write int in byte
*/

#include "writer.h"
#include "my.h"

unsigned int write_header(header_t *header, UNUSED char *filename, FILE *file)
{
    size_t err = 0;

    err = fwrite(header, 1, sizeof(header_t), file);

    if (err != sizeof(header_t)) {
        return 84;
    }
    return 0;
}
