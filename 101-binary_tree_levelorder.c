#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * binary_tree_size - counts amount of nodes in a tree
 *
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
 * binary_tree_levelorder - goes through a tree using levelorder traversal
 *
 * @tree: pointer to the root of the tree to raverse
 * @func: fonction to use on each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t parent = 0, child = 1, i;
	const size_t tree_size = binary_tree_size(tree);
	const binary_tree_t *node_array[10000];

	/*fill array with pointer to the nodes in corect order*/
	if (!tree || !func)
	return;
	node_array[0] = tree;
	while (child < tree_size)
	{
		if (node_array[parent]->left)
		{
			node_array[child] = node_array[parent]->left;
			child++;
		}
		if (node_array[parent]->right)
		{
			node_array[child] = node_array[parent]->right;
			child++;
		}
		parent++;
	}
	/*execute every node*/
	for (i = 0; i < tree_size; i++)
		func(node_array[i]->n);
}
