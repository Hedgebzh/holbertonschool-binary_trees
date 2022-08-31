#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
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
 * is_bst_minmax - fucntion used by binary_tree_is_bst keeps track of min/max
 *
 * @tree: tree to check
 * @max: max valu it can have
 * @min: min valu it can have
 * Return: 1 if true or 0
 */

int is_bst_minmax(const binary_tree_t *tree, int min, int max)
{
	printf("%d, %d\n", min, max);
	if (tree->n <= min || tree->n >= max)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	if (!tree->left)
		return (is_bst_minmax(tree->right, ISMIN(min, tree->n), max));
	if (!tree->right)
		return (is_bst_minmax(tree->left, min, ISMAX(max, tree->n)));
	if ((tree->left->n >= tree->n) || (tree->right->n <= tree->n))
		return (0);
	return (is_bst_minmax(tree->left, min, ISMAX(max, tree->n))
	* is_bst_minmax(tree->right, ISMIN(min, tree->n), max));
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
	return (is_bst_minmax(tree, INT_MIN, INT_MAX));
}
