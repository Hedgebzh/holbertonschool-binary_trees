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
