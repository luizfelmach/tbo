main: sieve.o main.c sieve.h
	gcc -O3 main.c sieve.o -o main -lm

sieve.o: sieve.h sieve.c
	gcc -c sieve.c -o sieve.o
	

clean:
	rm -rf main sieve.o
