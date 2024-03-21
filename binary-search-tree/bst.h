#ifndef BST_H
#define BST_H

#define BST_TYPE int

typedef struct bst_node_struct* bst_node;

bst_node bst_init();
bst_node bst_add(bst_node node, BST_TYPE item);
int bst_height(bst_node node);
void bst_free(bst_node);
void bst_traversal(bst_node node, void (*visit)(bst_node node));

void rec_pre_order_traversal(bst_node node);
void rec_in_order_traversal(bst_node node);
void rec_post_order_traversal(bst_node node);

#endif  // !BST_H
#define BST_H
