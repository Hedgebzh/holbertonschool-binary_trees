#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * binary_tree_node - créates a new node fon binary tree
 *
 * @parent: parent of the new node
 * @value: value in new node
 * Return: the node, use: parent->right(or left) = binary_tree_node(p,v);
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
		return (NULL);
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;
	new_node->n = value;
	return (new_node);
}
