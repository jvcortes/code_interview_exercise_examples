#ifndef BINARY_TREES
#define BINARY_TREES

#include <stdlib.h>
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;

void binary_tree_print(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t height(const binary_tree_t *tree);
heap_t *visit_node(binary_tree_t *node, int level);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);
heap_t *get_insertion_node(binary_tree_t *tree);
heap_t *heapify(heap_t *node);

#endif /* ifndef BINARY_TREES */
