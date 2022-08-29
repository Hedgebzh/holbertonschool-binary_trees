#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - créates a new node in left branch of binary tree
 *
 * @parent: parent of the new node
 * @value: value in new node
 * Return: the node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);
	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);
	new_node->left = parent->left;
	new_node->right = NULL;
	new_node->parent = parent;
	new_node->n = value;
	parent->left = new_node;
	if (new_node->left)
		new_node->left->parent = new_node;
	return (new_node);
}
