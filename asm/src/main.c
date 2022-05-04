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
    if (argc != 2)
        return usage(argv[0], EXIT_ERROR);
    if (!my_strcmp(argv[1], "-h"))
        return usage(argv[0], EXIT_SUCCESS);
    return EXIT_SUCCESS;
}
