main: stack.o main.c stack.h
	gcc -O3 main.c stack.o -o main -lm

stack.o: stack.h stack.c
	gcc -c stack.c -o stack.o
	

clean:
	rm -rf main stack.o
