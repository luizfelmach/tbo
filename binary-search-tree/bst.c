#include "bst.h"

#include <malloc.h>
#define MAX(a, b) (a > b) ? a : b

struct bst_node_struct {
    int key;
    bst_node right;
    bst_node left;
};

int bst_node_compare(BST_TYPE i1, BST_TYPE i2) { return i1 - i2; }

bst_node bst_node_create(BST_TYPE key) {
    bst_node node = (bst_node)calloc(sizeof(struct bst_node_struct), 1);
    node->key = key;
    return node;
}

bst_node bst_init() { return NULL; }

bst_node bst_add(bst_node node, BST_TYPE item) {
    if (node == NULL) return bst_node_create(item);
    int c = bst_node_compare(node->key, item);

    if (c > 0) {
        node->left = bst_add(node->left, item);
    } else if (c < 0) {
        node->right = bst_add(node->right, item);
    }
    return node;
}

int _bst_height(bst_node node, int cur) {
    if (node == NULL) return cur - 1;
    int a = _bst_height(node->right, cur + 1);
    int b = _bst_height(node->left, cur + 1);
    return MAX(a, b);
}

int bst_height(bst_node node) { return _bst_height(node, 0); }

void bst_free(bst_node node) {
    if (node == NULL) return;
    bst_free(node->right);
    bst_free(node->left);
    free(node);
}
