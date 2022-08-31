#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * is_bst_minmax - checks if tree is a binary search tree
 *
 * @tree: tree to check
 * @max: max valu it can have
 * @min: min valu it can have
 * Return: 1 if true or 0
 */

int is_bst_minmax(const binary_tree_t *tree, int min, int max)
{
	if (tree->n <= min || tree->n >= max)
		return (0);
	if (tree && !tree->left && !tree->right)
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
 * binary_tree_size - counts amount of nodes in a tree
 * @tree: root of tree to count
 * Return: the result
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: if tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		if (tree && !tree->left && !tree->right)
			return (0);

		return (MAX(binary_tree_height(tree->left),
		binary_tree_height(tree->right)) + 1);
	}
	return (0);
}

/**
 * binary_tree_is_almost_perfect - Measures if the
 *		tree is has less than 1 height difference
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: if tree is NULL, your function must return 0, else return height.
 */
int binary_tree_is_almost_perfect(const binary_tree_t *tree)
{
	int height_t = 0, i, j, pow2;
	size_t node_count = 0;

	if (!tree)
		return (0);

	height_t = binary_tree_height(tree);

	for (i = 0; i <= height_t; i++)
	{
		for (j = 1, pow2 = 1; j < i; j++)
			pow2 *= 2;
		node_count += pow2;
	}
	return (binary_tree_size(tree) <= (node_count * 2)
	&& binary_tree_size(tree) > node_count);
}

/**
 * binary_tree_is_avl - checks if tree is binary search tree
 *
 * @tree: tree to check
 * Return: 1 if true or 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->parent)
		return (1);
	return (is_bst_minmax(tree, INT_MIN, INT_MAX) *
	binary_tree_is_almost_perfect(tree));
}
