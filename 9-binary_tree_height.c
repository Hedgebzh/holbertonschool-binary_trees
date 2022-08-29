#include "binary_trees.h"
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
