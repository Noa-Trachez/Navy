##
## EPITECH PROJECT, 2021
## my_printf
## File description:
## makefile for my_printf
##

LIB = -L lib/my -lmy

all:
	$(MAKE) build_folders
	mv *.o ../

build_folders:
	make -s -C src/casts/
	make -s -C src/formats/
	make -s -C src/get_formats/
	make -s -C src/print/

clean:
	find . -name "*.o" -delete
	make -s -C src/casts/ clean
	make -s -C src/formats/ clean
	make -s -C src/get_formats/ clean
	make -s -C src/print/ clean

fclean: clean

re:	fclean all
