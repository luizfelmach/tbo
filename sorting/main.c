#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "item.h"

extern void sort(Item *a, int lo, int hi);

void printArray(Item *a, int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("usage: %s n\n", argv[0]);
        exit(1);
    }
    int N = atoi(argv[1]);

    Item *array = (Item *)malloc(N * sizeof(Item));

    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    clock_t start = clock();

    sort(array, 0, N - 1);

    clock_t end = clock();

    double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Array ordenado: ");
    printArray(array, N);

    printf("Tempo de execução: %lf segundos\n", elapsed_time);

    free(array);

    return 0;
}
