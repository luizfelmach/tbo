main: bst.o main.c bst.h
	gcc -O3 main.c bst.o -o main -lm

bst.o: bst.h bst.c
	gcc -c bst.c -o bst.o
	

clean:
	rm -rf main bst.o
