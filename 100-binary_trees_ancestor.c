#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * binary_tree_depth - finds depth of curent node
 *
 * @tree: node to find depth of
 * Return: the result
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int res = 0;

	if (!tree)
		return (0);
	while (tree->parent)
	{
		res++;
		tree = tree->parent;
	}
	return (res);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: first node to find ancestor of
 * @second: second node to find ancestor of
 * Return: common ancestor
 */
binary_tree_t *binary_trees_ancestor(binary_tree_t *first, binary_tree_t *second)
{
	size_t depth_first = binary_tree_depth(first);
	size_t depth_second = binary_tree_depth(second);
	size_t i;

	/*make sure both nodes are at same depth*/
	if (depth_first > depth_second)
	{
		for (i = 0; i < (depth_first - depth_second); i++)
			first = first->parent;
	}
	if (depth_first < depth_second)
	{
		for (i = 0; i < (depth_second - depth_first); i++)
			second = second->parent;
	}

	/*compare*/
	while (second && first)
	{
		if (second == first)
			return (second);
		second = second->parent;
		first = first->parent;
	}

	return (NULL);
}

