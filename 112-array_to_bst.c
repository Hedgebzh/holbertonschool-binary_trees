#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"
/**
 * binary_tree_delete - deletes a binary tree.
 * @tree: pointer to the root node of the tree to delete.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
/**
 * array_to_bst - creates a binary search tree frome array
 *
 * @array: the array to create frome
 * @size: size of array
 * Return: the binary search tree
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *new_tree = NULL;

	for (i = 0; i < size; i++)
	{
		if (!bst_insert(&new_tree, array[i]))
		{
			binary_tree_delete(new_tree);
			return (NULL);
		}
	}
	return (new_tree);
}
