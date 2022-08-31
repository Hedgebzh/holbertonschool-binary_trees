#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * binary_tree_is_leaf - checks if node is a leaf
 *
 * @node: node to check
 * Return:1 if true or 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return (node && !node->left && !node->right);
}

/**
 * binary_tree_is_bst - checks if tree is binary search tree
 *
 * @tree: tree to check
 * Return: 1 if true or 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	if (!tree->left)
		return (binary_tree_is_full(tree->right));
	if (!tree->right)
		return (binary_tree_is_full(tree->left));
	if ((tree->left->n > tree->n) || (tree->right->n < tree->n))
		return (0);
	return (binary_tree_is_full(tree->left) * binary_tree_is_full(tree->right));
}
