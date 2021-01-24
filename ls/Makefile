##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile for My_ls
##

SRC	=	flag_ls.c\
		my_strcmp.c\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls


all:	libcreate compile clean libclean

libcreate:
	make -C lib/my all

compile:	$(OBJ)
	gcc -g $(OBJ) -o $(NAME) -Wall -Wextra -L./ -lmy

libclean:
	make -C ./lib/my clean

libfclean:
	make -C ./lib/my fclean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean compile
