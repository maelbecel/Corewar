/*
** EPITECH PROJECT, 2022
** corewar.c
** File description:
** corewar
*/

#ifndef ASM_H_
    #define ASM_H_

    ////////////////////////////////////////////////////////////
    /// Headers
    ////////////////////////////////////////////////////////////
    #include <stdbool.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include "op.h"

    ////////////////////////////////////////////////////////////
    /// \def EXIT_ERROR
    ////////////////////////////////////////////////////////////
    #define EXIT_ERROR 84

    ////////////////////////////////////////////////////////////
    /// \def TAB
    ////////////////////////////////////////////////////////////
    #define TAB '\t'

    ////////////////////////////////////////////////////////////
    /// \def SPACE
    ////////////////////////////////////////////////////////////
    #define SPACE ' '

    ////////////////////////////////////////////////////////////
    /// \def QUOTES
    ////////////////////////////////////////////////////////////
    #define QUOTES '\"'

    ////////////////////////////////////////////////////////////
    /// \def UNINT_SIZE
    ////////////////////////////////////////////////////////////
    #define UINT_SIZE 4294967295

    ////////////////////////////////////////////////////////////
    /// \def SHORT_SIZE
    ////////////////////////////////////////////////////////////
    #define SHORT_SIZE 65535
    ////////////////////////////////////////////////////////////
    /// Structures
    ////////////////////////////////////////////////////////////
    typedef struct instruction_s instruction_t;
    typedef struct is_s is_t;

    ////////////////////////////////////////////////////////////
    /// Enumerations
    ////////////////////////////////////////////////////////////
    typedef enum type TYPE;
    typedef enum attribut ATTRIBUT;

    ////////////////////////////////////////////////////////////
    /// \brief Enumerates type of asm.
    ////////////////////////////////////////////////////////////
    enum type {
        T_OTHER,
        T_SPACE,
        TP_DIR,
        T_LABEL,
        T_SEPARATOR,
    };

    ////////////////////////////////////////////////////////////
    /// \brief Enumerates attribut of type of asm.
    ////////////////////////////////////////////////////////////
    enum attribut {
        D_NORMAL,
        D_GET,
        D_SEPARATOR,
        D_REG,
        D_DIR,
        D_IND,
    };

    ////////////////////////////////////////////////////////////
    /// \brief Is element structure.
    ///
    /// Contain the char, it type and it attribut.
    /// Allow to get the type and attribut of a char.
    ///
    /// \struct is_s is_t
    ////////////////////////////////////////////////////////////
    struct is_s {
        char token;
        ATTRIBUT attribut;
        TYPE type;
    };

    ////////////////////////////////////////////////////////////
    /// \brief Is instruction structure.
    ///
    /// Contain all information of an instrution:
    /// It string, it attribut, it type, and the next/previous instruction.
    ///
    /// \struct is_s is_t
    ////////////////////////////////////////////////////////////
    struct instruction_s {
        char *str;
        ATTRIBUT attribut;
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

    ////////////////////////////////////////////////////////////
    /// \brief Free the instruction array
    ///
    /// \param instruction  the instruction array that go to be free
    ///
    ////////////////////////////////////////////////////////////
    void free_instructions(instruction_t **instructions);

int check_error_instruction(instruction_t *instruction);

    ////////////////////////////////////////////////////////////
    /// \brief Return the mnemonique associated to a string
    ///
    /// \param str  the string
    ///
    /// \return The pos (number) of the mnemonique
    ///
    ////////////////////////////////////////////////////////////
    int get_op(char *str);

int error_params(instruction_t *instruction);
instruction_t *parse_instruction(char *av);
void clean_instruction(instruction_t *instruction);
bool check_instruction(instruction_t *line);
bool check_error_label(instruction_t **instructions);
bool count_nbr_label(char **list_label);
char *my_charcat(char *str, char c);
void get_champion_size(header_t *header, instruction_t **instructions);
int get_instruction_size(instruction_t *instruction, bool is_short);
short compute_size_short(instruction_t *tmp);
bool is_index_type(char *str);
void *get_params_size(ATTRIBUT attribut, bool index_params);

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
    /// \param type  the type of the instruction
    /// \param attribut  the attribut of the instruction
    ///
    /// \return The created instruction if have no error, EXIT_ERROR otherwise
    ///
    ////////////////////////////////////////////////////////////
    instruction_t *create_instruction(char *str, TYPE type, ATTRIBUT attribut);

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
