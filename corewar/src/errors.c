/*
** EPITECH PROJECT, 2022
** Corewar
** File description:
** get_option
*/

#include "my.h"
#include "printf.h"
#include "corewar.h"
#include "op.h"

int error(char *str)
{
    write(2, str, my_strlen(str));
    exit(84);
    return 0;
}