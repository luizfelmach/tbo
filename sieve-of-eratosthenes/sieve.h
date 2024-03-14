#ifndef SIEVE_H
#define SIEVE_H

int *sieve_int(int N);
int sieve_check_int(int *sieve, int n);
void sieve_free_int(int *sieve);

char *sieve_char(int N);
int sieve_check_char(char *sieve, int n);
void sieve_free_char(char *sieve);

int *sieve_bit(int N);
int sieve_check_bit(int *sieve, int n);
void sieve_free_bit(int *sieve);

#endif  // !SIEVE_H
