#include <malloc.h>
#include <math.h>

int *sieve_int(int N) {
    int i, j;
    int *sieve_mark = (int *)calloc(sizeof(int), N);

    i = 2;
    while (1) {
        if (i >= N) break;
        if (sieve_mark[i]) {
            i += 1;
            continue;
        }

        for (j = i + i; j < N; j += i) sieve_mark[j] = 1;

        i += 1;
    }

    return sieve_mark;
}

int sieve_check_int(int *sieve, int n) { return !sieve[n]; }

void sieve_free_int(int *sieve) { free(sieve); }

char *sieve_char(int N) {
    int i, j;
    char *sieve_mark = (char *)calloc(sizeof(char), N);

    i = 2;
    while (1) {
        if (i >= N) break;
        if (sieve_mark[i]) {
            i += 1;
            continue;
        }

        for (j = i + i; j < N; j += i) sieve_mark[j] = 1;

        i += 1;
    }

    return sieve_mark;
}

int sieve_check_char(char *sieve, int n) { return !sieve[n]; }

void sieve_free_char(char *sieve) { free(sieve); }

void *sieve_bit(int N) {
    int i, j, pos_int, result;
    int size = ceil((N + 1) / 32.0);
    int *sieve_mark = (int *)calloc(sizeof(int), size);

    i = 2;
    while (1) {
        if (i >= N) break;

        pos_int = i / 32;
        int pos = 1 << i % 32;
        result = pos & sieve_mark[pos_int];

        if (result) {
            i += 1;
            continue;
        }

        for (j = i + i; j < N; j += i) {
            pos_int = j / 32;
            int pos = 1 << j % 32;
            result = pos | sieve_mark[pos_int];
            sieve_mark[pos_int] = result;
        }

        i += 1;
    }

    return sieve_mark;
}

int sieve_check_bit(int *sieve, int n) {
    int pos_int = n / 32;
    int pos = 1 << n % 32;
    int result = pos & sieve[pos_int];
    return !result;
}

void sieve_free_bit(int *sieve) { free(sieve); }
