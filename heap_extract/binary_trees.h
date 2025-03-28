#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>

/* Structure Definition */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} heap_t;

/* Function Prototypes */
int heap_extract(heap_t **root);
heap_t *get_last_node(heap_t *root);
void heapify_down(heap_t *tree);

#endif /* BINARY_TREES_H */

