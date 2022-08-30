#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int power2(int n)
{
	int result = 1, i;

	for (i = 0; i < n; i++)
	{
		result *= 2;
	}
	return (result);
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
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: if tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		if (binary_tree_is_leaf(tree))
			return (0);

		return (MAX(binary_tree_height(tree->left),
		binary_tree_height(tree->right)) + 1);
	}
	return (0);
}

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height_t = 0, i;
	size_t node_count = 0;

	if(!tree)
		return (0);

	height_t = binary_tree_height(tree);

	for (i = 0; i <= height_t; i++)
	{
		node_count += power2(i);
	}
	return (binary_tree_size(tree) == node_count);
}
