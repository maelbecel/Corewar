/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** write char* in byte
*/

#include <stdio.h>
#include "writer.h"

unsigned int write_str(char *str, char *filename, FILE *file)
{
    size_t err = 0;

    err = fwrite(str, 1, strlen(str), file);

    if (err != strlen(str)) {
        return 84;
    }
    return 0;
}
