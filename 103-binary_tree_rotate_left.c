#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * binary_tree_rotate_left - rotate left
 *
 * @tree: node to rotate
 * Return: new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp = NULL;

	if (tree && tree->right)
	{
		tmp = tree->right;
		tree->right = tmp->left;
		tree->parent = tmp;
		tmp->left = tree;
		tmp->parent = NULL;
	}
	return (tmp);
}
