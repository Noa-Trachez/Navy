##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile for libmy
##

NAME = libmy.a

FLAGS = -c -Wall -Wextra

GCC = gcc $(FLAGS)

all:
	$(MAKE) compile
	$(MAKE) build
	$(MAKE) move
	$(MAKE) clean -s

compile:
	make -s -C iomanip/
	make -s -C linked_list/
	make -s -C others/
	make -s -C strmanip/
	make -s -C my_printf/

build:
	ar rc $(NAME) *.o

move:
	mkdir -p ../../include/lib
	cp include/*.h ../../include/lib

clean:
	find . -name "*.o" -delete

fclean:
	$(MAKE) clean
	rm -f libmy.a

re:
	$(MAKE) fclean
	$(MAKE) all
