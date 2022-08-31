#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * binary_tree_rotate_right - rotate right
 *
 * @tree: node to rotate
 * Return: new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp = NULL;

	if (tree && tree->left)
	{
		tmp = tree->left;
		tree->left = tmp->right;
		if (tree->left)
			tree->left->parent = tree;
		tree->parent = tmp;
		tmp->right = tree;
		tmp->parent = NULL;
	}
	return (tmp);
}
