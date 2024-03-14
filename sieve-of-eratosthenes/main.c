#include <stdio.h>
#include <stdlib.h>

#include "sieve.h"

#define SIEVE_INIT sieve_bit
#define SIEVE_CHECK sieve_check_bit
#define SIEVE_FREE sieve_free_bit
#define TYPE int *

int main(int argc, char **argv) {
    int N = 100, i;
    if (argc == 2) N = atoi(argv[1]);

    TYPE sieve = SIEVE_INIT(N);

    for (i = 2; i < N; i++) {
        if (SIEVE_CHECK(sieve, i)) printf("%d\n", i);
    }

    SIEVE_FREE(sieve);

    return 0;
}
