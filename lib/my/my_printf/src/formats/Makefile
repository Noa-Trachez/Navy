##
## EPITECH PROJECT, 2021
## my_printf
## File description:
## makefile for formats
##

SRC = \
	format_flags.c \
	format_precision.c \
	format_width.c \
	format.c

OBJ = $(SRC:.c=.o)

INCLUDE = ./../../include/

LIB = ./../../lib/my

FLAGS = -Wall -Wextra

CRITERION = -lcriterion --coverage

all:
	gcc $(FLAGS) -c $(SRC) -I$(INCLUDE) -L $(LIB)
	cp $(OBJ) ../../

tests:
	$(MAKE) clean
	gcc $(FLAGS) -c $(SRC) -I $(INCLUDE) -L $(LIB) $(CRITERION)
	cp $(OBJ) ../../

clean:
	rm -f $(OBJ)

re:
	$(MAKE) clean
	all
