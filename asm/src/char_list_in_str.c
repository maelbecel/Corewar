/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** check if char of an str are in another str
*/

#include "my.h"
#include "printf.h"
#include "asm.h"
#include "op.h"

bool char_list_in_str(char *str, char *src)
{
    size_t check = 0;

    for (int pos_str = 0; str[pos_str] != '\0'; pos_str++) {
        check = 0;
        for (int pos_src = 0; src[pos_src] != '\0'; pos_src++)
            if (str[pos_str] == src[pos_src])
                check++;
        if (check == 0)
            return false;
    }
    return true;
}
