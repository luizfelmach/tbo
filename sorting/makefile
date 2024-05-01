CC = gcc
CFLAGS = -Wall

SORT ?= insertion-sort

all: main

main: main.o $(SORT).o
	$(CC) $(CFLAGS) -o main main.o $(SORT).o

main.o: main.c item.h
	$(CC) $(CFLAGS) -c main.c

$(SORT).o: $(SORT).c item.h
	$(CC) $(CFLAGS) -c $(SORT).c

clean:
	rm -f main *.o

