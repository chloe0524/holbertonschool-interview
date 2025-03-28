#include "binary_trees.h"

void remove_top(heap_t *);

/**
 * heap_extract - extracts the top value of binary heap
 * @root: pointer to root node of heap address
 * Return: top value (root node)
 */
int heap_extract(heap_t **root)
{
	int max;

	if (!*root)
		return (0);

	/* max : value n of top node */
	max = (*root)->n;

	remove_top(*root);
	return (max);
}

/**
 * remove_top - removes top node and reorganizes tree
 * @tree: pointer to current node
 * Return: void
 */
void remove_top(heap_t *tree)
{
	heap_t *current_top;

	/* Base checks, end recursivity */
	if (!tree->left)
		return;

	current_top = tree->left;
	if (tree->right && tree->right->n > tree->left->n)
		current_top = tree->right;

	tree->n = current_top->n;

	if (current_top->left)
		/* Proceed with recursivity until last left */
		remove_top(current_top);
	else
	{
		/* Node has a parent and current is parent left => end left with NULL */
		/* Avoids duplicate node */
		if (current_top->parent && current_top->parent->left == current_top)
			current_top->parent->left = NULL;

		/* Node has a parent and current is parent right => end rigth with NULL */
		/* Avoids duplicate node */
		if (current_top->parent && current_top->parent->right == current_top)
			current_top->parent->right = NULL;
		free(current_top);
	}
}

