##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for corewar
##

NAME         	=		    asm

INCLUDE      	=         	-I ../include/ -I ../include/lib/ -L ../lib/ \
						-lmy -lmyprintf

CFLAGS         +=         	-Wall -Wextra $(INCLUDE)

SRC_DIR      	=         	src/
PARSER_DIR      =         	parser/
INSTRUC_DIR      =         	instructions/
HEADER      =         	header/

SRC          	=         	$(SRC_DIR)main.c 								\
							$(SRC_DIR)op.c 									\
							$(SRC_DIR)help.c 								\
							$(SRC_DIR)assembler.c 							\
							$(SRC_DIR)char_list_in_str.c 							\
							$(SRC_DIR)$(PARSER_DIR)$(HEADER)get_header.c 			\
							$(SRC_DIR)$(PARSER_DIR)$(HEADER)get_clean_line.c 		\
							$(SRC_DIR)$(PARSER_DIR)$(HEADER)get_name.c 				\
							$(SRC_DIR)$(PARSER_DIR)$(HEADER)get_comment.c			\
							$(SRC_DIR)$(PARSER_DIR)$(HEADER)get_quote_str.c			\
							$(SRC_DIR)$(PARSER_DIR)$(INSTRUC_DIR)get_instructions.c		\
							$(SRC_DIR)$(PARSER_DIR)$(INSTRUC_DIR)realloc_instructions.c		\
							$(SRC_DIR)$(PARSER_DIR)$(INSTRUC_DIR)free_instructions.c		\
							$(SRC_DIR)$(PARSER_DIR)$(INSTRUC_DIR)create_instruction.c		\
							$(SRC_DIR)$(PARSER_DIR)$(INSTRUC_DIR)insert_instruction.c		\
							$(SRC_DIR)$(PARSER_DIR)$(INSTRUC_DIR)pop.c		\
							$(SRC_DIR)$(PARSER_DIR)$(INSTRUC_DIR)go_to_last.c		\
							$(SRC_DIR)$(PARSER_DIR)$(INSTRUC_DIR)pop_next.c		\
							$(SRC_DIR)$(PARSER_DIR)$(INSTRUC_DIR)clean_instructions.c		\
							$(SRC_DIR)$(PARSER_DIR)$(INSTRUC_DIR)error_params.c		\
							$(SRC_DIR)$(PARSER_DIR)$(INSTRUC_DIR)error_syntax_line.c		\
							$(SRC_DIR)$(PARSER_DIR)$(INSTRUC_DIR)check_instruction.c		\
							$(SRC_DIR)$(PARSER_DIR)$(INSTRUC_DIR)error_label.c		\
							$(SRC_DIR)$(PARSER_DIR)tokeniser.c		\

SRC_COUNT    	=         	$(words $(SRC))

NB           	=         	0

OBJ          	=	        $(SRC:.c=.o)

TEMPFILES    	=         	*~ *vgcore* #*#

RM           	=         	rm -f

ECHO         	=         	/bin/echo -e
DEFAULT      	=         	"\033[00m"
BOLD         	=         	"\e[1m"
RED          	=         	"\e[31m"
GREEN        	=         	"\e[32m"
LIGHT_BLUE   	=         	"\e[94m"
WHITE        	=         	"\e[1;37m"

all:	$(NAME)

$(NAME):	$(OBJ)
			@echo
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE) \
			"SRC files sucessfully build. "$(DEFAULT))
			@make -C ../lib/my/ --no-print-directory
			@make -C ../lib/myprintf/ --no-print-directory
			@gcc -o $(NAME) $(OBJ) $(INCLUDE) \
			&& $(ECHO) $(BOLD) $(GREEN)"\n► BUILD SUCCESS !"$(DEFAULT) \
			|| ($(ECHO) $(BOLD) $(RED)"\n► BUILD FAILED"$(DEFAULT) && exit 1)

debug:		CFLAGS += -g3 -pg
debug:		all

clean:
			@make -C ../lib/my/ clean --no-print-directory
			@make -C ../lib/myprintf/ clean --no-print-directory
			@$(RM) $(OBJ)
			@$(RM) $(TEMPFILES)
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" Clean SRC "$(DEFAULT))

fclean:		clean
			@make -C ../lib/myprintf/ fclean --no-print-directory
			@make -C ../lib/my/ fclean --no-print-directory
			@$(RM) $(NAME)
			@$(RM) $(OBJ)
			@$(RM) $(TEMPFILES)
			@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" Fclean SRC "$(DEFAULT))

re:
			@make fclean --no-print-directory
			@make --no-print-directory

%.o:		%.c
			@$(eval NB=$(shell echo $$(($(NB)+1))))
			@gcc -c -o $@ $^ $(CFLAGS) && python3 ../build/build.py $< $(NB) \
			$(SRC_COUNT)

.PHONY: all re clean fclean debug
