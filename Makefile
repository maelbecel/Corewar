##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for corewar
##


all:	$(NAME)

$(NAME):
			@make -C corewar --no-print-directory
			@make -C asm --no-print-directory

debug:
			@make -C corewar debug --no-print-directory
			@make -C asm debug --no-print-directory

clean:
			@make -C corewar clean --no-print-directory
			@make -C asm clean --no-print-directory

fclean:
			@make -C corewar fclean --no-print-directory
			@make -C asm fclean --no-print-directory

re:
			@make -C corewar re --no-print-directory
			@make -C asm re --no-print-directory

.PHONY: all re clean fclean debug
