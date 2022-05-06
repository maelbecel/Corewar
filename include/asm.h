/*
** EPITECH PROJECT, 2022
** corewar.c
** File description:
** corewar
*/

#ifndef ASM_H_
    #define ASM_H_

    #include <stdbool.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include "op.h"

    #define EXIT_ERROR 84
    #define TAB '\t'
    #define SPACE ' '
    #define QUOTES '\"'

    ////////////////////////////////////////////////////////////
    /// \brief Write the usage and return the status
    ///
    /// \param binary  name of binary
    /// \param status the value of return
    ///
    /// \return The value of status
    ///
    ////////////////////////////////////////////////////////////
    int usage(char *binary, int status);

    ////////////////////////////////////////////////////////////
    /// \brief Write the usage and return a status
    ///
    /// \param file_name  the file to compile in .cor
    ///
    /// \return The value of status
    ///
    ////////////////////////////////////////////////////////////
    int assembler(char *file_name);

    ////////////////////////////////////////////////////////////
    /// \brief Get the .name and .comment in .s file
    ///
    /// \param file_name  the input file
    ///
    /// \return Struct header with the name and comment
    ///
    ////////////////////////////////////////////////////////////
    header_t *get_header(FILE *file_name, char **line);

    ////////////////////////////////////////////////////////////
    /// \brief A getline function, opti
    ///
    /// \param file_name  the input file
    ///
    /// \return Line of a file
    ///
    ////////////////////////////////////////////////////////////
    char *get_clean_line(FILE *file_name);

    ////////////////////////////////////////////////////////////
    /// \brief Get the .name in .s file
    ///
    /// \param line  the line that contains the .name
    ///
    /// \return The name between the quotes
    ///
    ////////////////////////////////////////////////////////////
    char *get_name(char *line);

    ////////////////////////////////////////////////////////////
    /// \brief Get the .comment in .s file
    ///
    /// \param line  the line that contains the .comment
    ///
    /// \return The comment between the quotes
    ///
    ////////////////////////////////////////////////////////////
    char *get_comment(char *line);

    ////////////////////////////////////////////////////////////
    /// \brief Get a string between two double quotes
    ///
    /// \param line  the line that contains the double quotes
    ///
    /// \return The string
    ///
    ////////////////////////////////////////////////////////////
    char *get_quote_str(char *line);

#endif
