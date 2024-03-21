#ifndef BST_H
#define BST_H

#define BST_TYPE int

typedef struct bst_node_struct* bst_node;

bst_node bst_init();
bst_node bst_add(bst_node node, BST_TYPE item);
int bst_height(bst_node node);
void bst_free(bst_node);

#endif  // !BST_H
#define BST_H
