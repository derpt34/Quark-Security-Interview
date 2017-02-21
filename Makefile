/* (c) Daniel Levi Guise, 2017. */

CFLAGS = -g -ansi -pedantic-errors -Wall -Werror -Wshadow -Wwrite-strings
CC = gcc

world-times.x: world-times.o 
	$(CC) world-times.o -o world-times.x

world-times.o: world-times.c world-times.h world-times-datastructure.h
	$(CC) -c $(CFLAGS) world-times.c

clean:
	rm -f *.o *.x
