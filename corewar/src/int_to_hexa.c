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

char *int_to_hexa_string(int nb)
{
    int quotient = nb;
    int r;
    char *base = "0123456789abcdef";
    char *res = my_calloc(16 * (nb + 1));
    int j = 0;

    if (!res)
        return NULL;
    while (quotient != 0) {
        r = quotient % 16;
        res[j] = base[r];
        res[++j] = '\0';
        quotient /= 16;
    }
    if (!res[1]) {
        res[1] = '0';
        res[2] = '\0';
    }
    return (nb == 0) ? my_strdup("00") : my_revstr(res);
}
