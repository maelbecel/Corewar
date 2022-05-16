/*
** EPITECH PROJECT, 2022
** corewar.c
** File description:
** corewar
*/

#ifndef WRITER_H_
    #define WRITER_H_

    #define EXTENTION ".cor"

    #include <stdio.h>
    #include "asm.h"
    #include "op.h"

    ////////////////////////////////////////////////////////////
    /// \brief Write header_t* in byte
    ///
    /// \return return value (usigned int) 84 if error
    ///
    ////////////////////////////////////////////////////////////
    unsigned int write_header(header_t *header, char *filename, FILE *file);

    ////////////////////////////////////////////////////////////
    /// \brief Handler of the compilation process to write the code in byte
    ///
    /// \return return value (usigned int) 84 if error
    ///
    ////////////////////////////////////////////////////////////
    unsigned int write_code(header_t *header, instruction_t **instructions,
                                                            char *filename);

    ////////////////////////////////////////////////////////////
    /// \brief Handler of the compilation of instructions
    ///
    /// \return return value (usigned int) 84 if error
    ///
    ////////////////////////////////////////////////////////////
    unsigned int write_instructions(instruction_t **instructions, FILE *file);

    ////////////////////////////////////////////////////////////
    /// \brief strcat like with malloc
    ///
    /// \return return value (unsigned int) 84 if error
    ///
    ////////////////////////////////////////////////////////////
    unsigned int write_instruction(instruction_t *instruction, FILE *file);

    ////////////////////////////////////////////////////////////
    /// \brief strcat like with malloc
    ///
    /// \return return value (char *) NULL if error
    ///
    ////////////////////////////////////////////////////////////
    char *concatener(char *dest, char const *src);

    ////////////////////////////////////////////////////////////
    /// \brief write codebyte parameters
    ///
    /// \return return void
    ///
    ////////////////////////////////////////////////////////////
    void write_codebytes(instruction_t *instruction, FILE *file);

#endif /* WRITER_H_ ! */
