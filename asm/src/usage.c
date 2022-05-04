/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "asm.h"

const char *usage_msg[] = {
    " file_name[.s]\n",
    "DESCRIPTION\n",
    "file_name file in assembly language to be converted into file_name.cor,",
    "an\nexecutable in the Virtual Machine.\n",
    NULL
};

int usage(char *binary, int status)
{
    my_putstr("USAGE\n");
    my_putstr(binary);
    for (size_t i = 0; usage_msg[i] != NULL; i++)
        my_putstr(usage_msg[i]);
    return status;
}
