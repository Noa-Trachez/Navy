##
## EPITECH PROJECT, 2021
## B-PSU-101-LIL-1-1-navy-quentin.desmettre
## File description:
## Makefile
##

all:
	make -s -C src/
	mv src/navy ./

clean:
	make -s -C src/ clean

fclean:
	make -s -C src/ fclean
	rm -f navy

re:
	make -s -C src/ fclean
	$(MAKE) all -s
