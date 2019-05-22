##
## EPITECH PROJECT, 2019
## mlib
## File description:
## Makefile, create by Axel Virot
##

SRC     =       marg.c			\
		marray.c		\
		marr_cp.c		\
		mcond.c			\
		mgetline.c		\
		mgetnbr.c		\
		mputnbr.c		\
		mputstr.c		\
		mstrcat.c		\
		mstrcmp.c		\
		mstr_cp.c		\

OBJ     =	$(SRC:.c=.o)

NAME    =	libm.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar -rc $(NAME) $(OBJ)
	cp ./mlib.h ../../include/

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
