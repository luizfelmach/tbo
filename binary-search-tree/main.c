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

    // root = bst_add(root, 10);
    // root = bst_add(root, 6);
    // root = bst_add(root, 4);
    // root = bst_add(root, 5);
    // root = bst_add(root, 20);
    // root = bst_add(root, 14);
    // root = bst_add(root, 1);
    // root = bst_add(root, 11);
    //
    for (i = 0; i < n; i++) {
        root = bst_add(root, rand());
    }

    printf("Height: %d\n", bst_height(root));

    printf("Pre Order: ");
    bst_traversal(root, rec_pre_order_traversal);
    printf("\nIn Order: ");
    bst_traversal(root, rec_in_order_traversal);
    printf("\nPost Order: ");
    bst_traversal(root, rec_post_order_traversal);

    bst_free(root);
    return 0;
}
