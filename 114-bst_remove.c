#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"
/**
 * bst_search - search for node in tree
 *
 * @tree: tree to search in
 * @value: value to find
 * Return: pointer to node if found NULL othertwise
 */
bst_t *bst_search(bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (value > tree->n)
		return (bst_search(tree->right, value));
	if (value < tree->n)
		return (bst_search(tree->left, value));
	return (tree);
}
/**
 * bst_remove - removes a value frome tree
 *
 * @root: tree to remove frome
 * @value: value to remove
 * Return: pointer to the node that took its place
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node;
	bst_t *successor;

	node = bst_search(root, value);
	if (!node)
		return (NULL);
	successor = node->right;
	if (!successor)
	{
		if (node->parent && node->parent->left == node)
			node->parent->left = node->left;
		else if (node->parent && node->parent->right == node)
			node->parent->right = node->left;
		else
			root = node->left;
		if (node->left)
			node->left->parent = node->parent;
		free(node);
		return (root);
	}
	if (!successor->left)
	{
		node->n = successor->n;
		successor->parent->right = successor->right;
		successor->right->parent = successor->parent;
		free(successor);
		return (root);
	}
	while (successor->left)
		successor = successor->left;
	node->n = successor->n;
	successor->parent->left = successor->right;
	if (successor->right)
		successor->right->parent = successor->parent;
	free(successor);
	return (root);
}
