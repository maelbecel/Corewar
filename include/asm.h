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

    typedef struct instruction_s instruction_t;
    typedef enum id ID;
    typedef enum type TYPE;
    typedef struct parser_s parser_t;

    enum id {
        ID_WIHOUT,
        ID_SPACE,
        ID_DIR,
        ID_LABEL,
        ID_SEPARATOR,
    };

    enum type {
        D_NORMAL,
        D_GET,
        D_SEPARATOR,
        D_REG,
        D_DIR,
        D_IND,
    };

    struct parser_s{
        char token;
        TYPE type;
        ID id;
    };

    struct instruction_s{
        char *str;
        ID id;
        TYPE type;
        struct instruction_s *next;
        struct instruction_s *prev;
    };

    ////////////////////////////////////////////////////////////
    /// \brief Write the help and return the status
    ///
    /// \param binary  name of binary
    /// \param status the value of return
    ///
    /// \return The value of status
    ///
    ////////////////////////////////////////////////////////////
    int help(char *binary, int status);

    ////////////////////////////////////////////////////////////
    /// \brief Write the help and return a status
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

    ////////////////////////////////////////////////////////////
    /// \brief Get all of instruction after header and fill a struct with it
    ///
    /// \param line  the line of instruction
    /// \param source_file  the file that contains instructions
    ///
    /// \return The string
    ///
    ////////////////////////////////////////////////////////////
    instruction_t **get_instructions(FILE *source_file, char *line);

void free_instructions(instruction_t **instructions);
int error_syntax_line(instruction_t *token);
int find_index_op(char *mnemonique);
int error_params(instruction_t *token);
instruction_t *tokeniser(char *av);
void clean_instructions(instruction_t *token);
bool correct_line(instruction_t *line);
bool error_label(instruction_t **array);

    ////////////////////////////////////////////////////////////
    /// \brief Realloc the instruction array
    ///
    /// \param instructions  the instruction array that needs to be realloc
    /// \param size  the size of the array
    ///
    /// \return The instruction array reallocated
    ///
    ////////////////////////////////////////////////////////////
    instruction_t **realloc_instructions(instruction_t **instructions,
                                                                size_t size);

    ////////////////////////////////////////////////////////////
    /// \brief Remove the next instruction of an instruction
    ///
    /// \param instruction  the instruction that go to delete it next
    ///
    /// \return EXIT_SUCCESS if have no error, EXIT_ERROR otherwise
    ///
    ////////////////////////////////////////////////////////////
    int pop_next(instruction_t *instruction);

    ////////////////////////////////////////////////////////////
    /// \brief Remove the instruction of the instruction array
    ///
    /// \param instruction  the instruction that go to be deleted
    ///
    /// \return EXIT_SUCCESS if have no error, EXIT_ERROR otherwise
    ///
    ////////////////////////////////////////////////////////////
    instruction_t *pop(instruction_t *instruction);

    ////////////////////////////////////////////////////////////
    /// \brief Check if a str contains char of another str
    ///
    /// \param str  the str that go to be compared
    /// \param src  the str filter
    ///
    /// \return true if all char correspond, false otherwise
    ///
    ////////////////////////////////////////////////////////////
    bool char_list_in_str(char *str, char *src);

    ////////////////////////////////////////////////////////////
    /// \brief Create a new instruction in array
    ///
    /// \param str  the string of the instruction
    /// \param id  the id of the instruction
    /// \param type  the type of the instruction
    ///
    /// \return The created instruction if have no error, EXIT_ERROR otherwise
    ///
    ////////////////////////////////////////////////////////////
    instruction_t *create_instruction(char *str, ID id, TYPE type);

    ////////////////////////////////////////////////////////////
    /// \brief Insert a new instruction in the instruction array
    ///
    /// \param start  the first instruction of the array
    /// \param new  the new instruction that be added
    ///
    /// \return EXIT_SUCCESS if have no error, EXIT_ERROR otherwise
    ///
    ////////////////////////////////////////////////////////////
    int insert_new_instruction(instruction_t *start, instruction_t *new);

    ////////////////////////////////////////////////////////////
    /// \brief Go and return the last instruction of instruction array
    ///
    /// \param new  the new instruction that be added
    ///
    /// \return EXIT_SUCCESS if have no error, EXIT_ERROR otherwise
    ///
    ////////////////////////////////////////////////////////////
    instruction_t *go_to_last(instruction_t *start);

#endif
