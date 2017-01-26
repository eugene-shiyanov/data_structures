CC = gcc --std=c11

.PHONY: all clean

all : bubblesort

bubblesort : bubblesort.o array_bub.o

array_bub.o : array_bub.c array_bub.h

bubblesort.o : bubblesort.c array_bub.h

clean :
	rm bubblesort *.o

