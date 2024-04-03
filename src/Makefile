##
## EPITECH PROJECT, 2021
## B-PSU-101-LIL-1-1-navy-quentin.desmettre
## File description:
## Makefile
##

SRC	=	main.c \
		error.c \
		map.c \
		connection.c \
		get_coord.c \
		send_coord.c \
		pos_hit.c \
		update_pos.c \
		print_maps.c \
		send_get_attack.c\
		fill_map.c\
		win_cond.c

CFLAGS	=	-W -Wall -Wextra -I ../include/

OBJ	=	$(SRC:.c=.o)

INCLUDE_LIB	=	-L ../lib/my/ -lmy

NAME	=	navy

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	make -s -C ../lib/my/
	gcc -o $(NAME) $(OBJ) $(INCLUDE_LIB)

clean	:
	make -s -C ../lib/my/ clean
	rm -rf $(OBJ)

fclean:
	$(MAKE) clean
	make fclean -s -C ../lib/my/
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
