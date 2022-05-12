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

static void check(size_t *correct, char *src, char *str, int pos_str)
{
    for (size_t pos_src = 0; src[pos_src] != '\0'; pos_src++)
        if (str[pos_str] == src[pos_src])
            (*correct)++;
}

bool char_list_in_str(char *str, char *src)
{
    size_t correct = 0;

    for (size_t pos_str = 0; str[pos_str] != '\0'; pos_str++) {
        correct = 0;
        check(&correct, src, str, pos_str);
        if (correct == 0)
            return false;
    }
    return true;
}
