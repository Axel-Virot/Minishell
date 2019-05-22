##
## EPITECH PROJECT, 2019
## minishell1
## File description:
## Makefile
##

SRC	=	src/main.c				\
		src/minishell.c				\
		src/execute.c				\
		src/builtin/set_builtin.c		\
		src/builtin/my_exit.c			\
		src/builtin/my_cd/my_cd.c		\
		src/builtin/my_cd/my_cd_no_arg.c	\
		src/builtin/my_cd/my_cd_setenv.c	\
		src/builtin/my_cd/my_cd_malus.c		\
		src/builtin/my_env.c			\
		src/builtin/my_setenv.c			\
		src/builtin/my_unsetenv.c		\
		src/tool/is_word_in_str.c		\
		src/tool/str_to_array_exec.c		\
		src/tool/command_parser.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -L./lib/mlib -lm -g3 -Wall -Wextra -Werror

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/mlib
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	make clean -C ./lib/mlib
	rm -f $(OBJ)

fclean:	clean
	make fclean -C ./lib/mlib
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
