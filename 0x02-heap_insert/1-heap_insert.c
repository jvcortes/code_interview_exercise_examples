#include <stdlib.h>
#include "binary_trees.h"


/**
 * heap_insert - inserts a node in a max binary heap.
 * @root: root node,
 * @value: value for the node.
 *
 * Return: newly created node, if memory allocation fails, the function
 * will return a null pointer.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node = get_insertion_node(*root);

	if (*root == NULL)
	{
		node = binary_tree_node(NULL, value);
		*root = node;
	}
	else
	{
		node->n = value;
	}

	node = heapify(node);

	return (node);
}


/**
 * heapify - relocates a max binary heap node if its value is greater than its
 * parent's.
 *
 * @node: node to relocate.
 *
 * Return: new location of the node, if the node hasn't been relocated,
 * the function will return its same pointer.
 */
heap_t *heapify(heap_t *node)
{
	int sw;
	heap_t *current = node;

	if (current->parent == NULL)
		return (node);

	while (current->n > current->parent->n)
	{
		sw = current->n;
		current->n = current->parent->n;
		current->parent->n = sw;

		current = current->parent;

		if (current->parent == NULL)
			break;
	}

	return (current);
}


/**
 * get_insertion_node - gets the closest insertion node for a binary heap,
 * using level traversal.
 * @tree: root node of the tree
 *
 * Return: pointer to the newly allocated node. If the function receives a
 * null pointer, it will return the same pointer.
 */
heap_t *get_insertion_node(binary_tree_t *tree)
{
	int h, l = 0;
	heap_t *node;

	if (tree == NULL)
		return (tree);

	h = height(tree);

	while (l++ <= h)
	{
		node = visit_node(tree, l);
		if (node != NULL)
			break;
	}

	return (node);
}


/**
 * visit_node - looks for the closest insertion node in a specific level of a
 * binary heap..
 *
 * @node: provided node.
 * @level: level of the heap.
 *
 * Return: pointer to the newly generated node.
 */
heap_t *visit_node(binary_tree_t *node, int level)
{
	binary_tree_t *tmp;

	if (level == 1)
	{
		if (node->left == NULL)
		{
			node->left = binary_tree_node(node, 0);
			return (node->left);
		}
		else if (node->right == NULL)
		{
			node->right = binary_tree_node(node, 0);
			return (node->right);
		}
	}
	else
	{
		tmp = visit_node(node->left, level - 1);
		if (tmp != NULL)
			return (tmp);
		tmp = visit_node(node->right, level - 1);
		if (tmp != NULL)
			return (tmp);
	}

	return (NULL);
}


/**
 * height - measures the height of a binary tree
 * @tree: pointer of the binary tree.
 *
 * Return: height of the binary tree.
 */
size_t height(const binary_tree_t *tree)
{
	size_t lh = 0, rh = 0;

	if (!tree)
		return (0);

	if (tree->left)
		lh = height(tree->left) + 1;
	if (tree->right)
		rh = height(tree->right) + 1;

	return (lh > rh ? lh : rh);
}
