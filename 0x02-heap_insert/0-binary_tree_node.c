#include <stdlib.h>
#include "binary_trees.h"


/**
 * binary_tree_node - inserts a node in a binary tree
 *
 * If parent is NULL, the node will be inserted at parent.
 * Else, the respective node will be inserted and its parent will
 * be set.
 *
 * @parent: parent node.
 * @value: value for the node.
 *
 * Return: newly inserted node. If memory allocation fails, the function will
 * return a null pointer.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	new->n = value;

	if (parent == NULL)
	{
		parent = new;
		return (parent);
	}
	else
	{
		new->parent = parent;
	}

	return (new);
}
