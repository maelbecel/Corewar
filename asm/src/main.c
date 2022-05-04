/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "asm.h"

int main (int argc, char **argv)
{
    int status = EXIT_SUCCESS;

    if (argc != 2)
        return usage(argv[0], EXIT_ERROR);
    if (my_strcmp(argv[1], "-h") == 0)
        return usage(argv[0], EXIT_SUCCESS);
    status = assembler(argv[1]);
    return status;
}
