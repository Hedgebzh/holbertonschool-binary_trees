#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"
/**
 * binary_tree_sibling - finds the sibling of a node
 *
 * @node: pointer to the node to find sibling of
 * Return: NUll if no sibling, or the pointer to sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node->parent->right == node)
		return (node->parent->left);
	return (node->parent->right);
}
/**
 * binary_tree_uncle - finds the uncle of a node
 *
 * @node: pointer to the node to find uncle of
 * Return: NUll if no uncle, or the pointer to uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{

	if (!node || !node->parent)
		return (NULL);
	return (binary_tree_sibling(node->parent));
}
