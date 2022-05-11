/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "asm.h"

const char *str[] = {
    " file_name[.s]\n",
    "DESCRIPTION\n",
    "file_name file in assembly language to be converted into file_name.cor, ",
    "an\nexecutable in the Virtual Machine.\n",
    NULL
};

int help(char *binary, int status)
{
    my_printf("USAGE\n%s", binary);
    for (size_t pos = 0; str[pos] != NULL; pos++)
        my_putstr(str[pos]);
    return status;
}
