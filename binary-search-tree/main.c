#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bst.h"

int main(int argc, char **argv) {
    int i, n = 100;
    srand(time(NULL));
    if (argc == 2) {
        n = atoi(argv[1]);
    }
    bst_node root = bst_init();

    for (i = 0; i < n; i++) {
        root = bst_add(root, rand());
    }

    printf("Height: %d\n", bst_height(root));

    bst_free(root);
    return 0;
}
