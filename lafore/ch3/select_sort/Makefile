CC = gcc -std=c11

.PHONY: all clean

all : selectsort

selectsort : selectsort.o array_sel.o

selectsort.o : selectsort.c array_sel.h

array_sel.o : array_sel.c array_sel.h

clean :
	rm selectsort *.o

