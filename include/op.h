/*
** EPITECH PROJECT, 2022
** corewar.c
** File description:
** corewar
*/

#ifndef _OP_H_
    # define _OP_H_
    # define MEM_SIZE                (6*1024)
    # define IDX_MOD                 512   /* modulo of the index < */
    # define NB_LINE                 12    /* nb of lines */
    # define MAX_ARGS_NUMBER         4     /* 2 ^ * IND_SIZE */

    # define COMMENT_CHAR            '#'
    # define LABEL_CHAR              ':'
    # define DIRECT_CHAR             '%'
    # define SEPARATOR_CHAR          44     /* ', ' */
    # define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"
    # define NAME_CMD_STRING         ".name"
    # define COMMENT_CMD_STRING      ".comment"

    # define REG_NUMBER      16              /* r1 < - > rx */

    # define IND_SIZE        2
    # define DIR_SIZE        4
    # define REG_SIZE        DIR_SIZE

    # define T_REG           1       /* register */
    # define T_DIR           2       /* direct  (ld  #1, r1  put 1 into r1)*/
    # define T_IND           4       /*indirect always relative */
    # define T_LAB           8       /* LABEL */

    # define PROG_NAME_LENGTH        128
    # define COMMENT_LENGTH          2048
    # define COREWAR_EXEC_MAGIC      0xea83f3        /* why not */

    # define CYCLE_TO_DIE    1536   /* number of cycle before being dead */
    # define CYCLE_DELTA     5
    # define NBR_LIVE        40

    typedef struct vm_s vm_t;
    typedef char args_type_t;
    typedef struct header_s header_t;

    typedef struct
    {
        char         *mnemonique;
        char         nbr_args;
        args_type_t  attribut[MAX_ARGS_NUMBER];
        char         code;
        int          nbr_cycles;
        char         *comment;
        void         (*func)(vm_t *vm, ...);
    } op_t;

    extern const op_t op_tab[];

    struct header_s
    {
        int  magic;
        char prog_name[PROG_NAME_LENGTH + 1];
        int  prog_size;
        char comment[COMMENT_LENGTH + 1];
    };

#endif
