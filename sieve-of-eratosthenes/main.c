#include <stdio.h>

#include "sieve.h"

#define SIEVE_INIT sieve_int
#define SIEVE_CHECK sieve_check_int
#define SIEVE_FREE sieve_free_int
#define TYPE int*

int main() {
    int N = 100, i;

    TYPE sieve = SIEVE_INIT(N);

    for (i = 2; i < N; i++) {
        if (SIEVE_CHECK(sieve, i)) printf("%d\n", i);
    }

    SIEVE_FREE(sieve);

    return 0;
}
