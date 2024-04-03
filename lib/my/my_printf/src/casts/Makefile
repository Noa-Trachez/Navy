##
## EPITECH PROJECT, 2021
## my_printf
## File description:
## makefile for casts
##

SRC = \
	get_raw_str.c \
	signed_casts.c \
	string_casts.c \
	unsigned_casts.c \
	var_to_str.c \
	floats.c

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
