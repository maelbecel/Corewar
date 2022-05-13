##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for corewar
##

NAME         =		    corewar

INCLUDE      =         -I ../include/ -I ../include/lib/ -L ../lib/ \
						-lmy -lmyprintf

CFLAGS      +=         -Wall -Wextra -Werror $(INCLUDE)

SOURCES      =         src/

ACTION 		 =  	   actions/

SRC          =         	$(SOURCES)main.c 				\
						$(SOURCES)op.c 					\
						$(SOURCES)errors.c 				\
						$(SOURCES)check_champion.c 		\
						$(SOURCES)get_option.c			\
						$(SOURCES)init_champ.c		 	\
						$(SOURCES)init_arene.c		 	\
						$(SOURCES)int_to_hexa.c		 	\
						$(SOURCES)fill_champ.c		 	\
						$(SOURCES)action.c			 	\
						$(SOURCES)my_calloc.c 		 	\
						$(SOURCES)init_prog.c			\
						$(SOURCES)get_data.c		 	\
						$(SOURCES)win.c					\
						$(SOURCES)$(ACTION)add.c		\
						$(SOURCES)$(ACTION)aff.c		\
						$(SOURCES)$(ACTION)and.c		\
						$(SOURCES)$(ACTION)fork.c		\
						$(SOURCES)$(ACTION)ld.c		 	\
						$(SOURCES)$(ACTION)ldi.c		\
						$(SOURCES)$(ACTION)lfork.c		\
						$(SOURCES)$(ACTION)live.c		\
						$(SOURCES)$(ACTION)lld.c		\
						$(SOURCES)$(ACTION)lldi.c		\
						$(SOURCES)$(ACTION)or.c		 	\
						$(SOURCES)$(ACTION)st.c		 	\
						$(SOURCES)$(ACTION)sti.c		\
						$(SOURCES)$(ACTION)sub.c		\
						$(SOURCES)$(ACTION)xor.c		\
						$(SOURCES)$(ACTION)zjmp.c		\

SRC_COUNT    =         $(words $(SRC))

NB           =         0

OBJ          =	        $(SRC:.c=.o)

TEMPFILES    =         *~ *vgcore* #*#

RM           =         rm -f

ECHO         =         /bin/echo -e
DEFAULT      =         "\033[00m"
BOLD         =         "\e[1m"
RED          =         "\e[31m"
GREEN        =         "\e[32m"
LIGHT_BLUE   =         "\e[94m"
WHITE        =         "\e[1;37m"

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
