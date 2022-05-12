/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** strcat like with malloc
*/

#include "my.h"

char *concatener(char *dest, char const *src)
{
    char *tmp;
    size_t pos_dest = 0;
    if (!dest)
        return my_strdup(src);
    else {
        tmp = malloc(sizeof(char) * (my_strlen(src) + my_strlen(dest) + 1));
        if (!tmp)
            return NULL;
        my_strcpy(tmp, dest);
        free(dest);
    }
    pos_dest = my_strlen(tmp);
    for (size_t pos_src = 0; src[pos_src] != '\0'; pos_dest++, pos_src++)
        tmp[pos_dest] = src[pos_src];
    tmp[pos_dest] = '\0';
    return tmp;
}
