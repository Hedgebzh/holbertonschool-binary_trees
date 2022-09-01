#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * avl_rec_create - recursivly creats an avl frome sorted array
 *
 * @tree: tree to modify
 * @array: array to use as template
 * @size: size of array
 */
void avl_rec_create(avl_t *tree, int *array, size_t size)
{
	size_t odd = size % 2;

	if (size > 1)
	{
		size = size / 2 - 1 + odd;
		if (size)
			tree->left = binary_tree_node(tree, array[size / 2 - 1 + (size % 2)]);
		tree->right = binary_tree_node(tree, array[size + size / 2 + 1]);
		avl_rec_create(tree->left, array, size);
		avl_rec_create(tree->right, array + size + 1, size + 1 - odd);
	}
}


/**
 * sorted_array_to_avl - creates an avl frome array
 *
 * @array: template array
 * @size: size of array
 * Return: pointer to the root of the new tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	root = binary_tree_node(NULL, array[size / 2 - 1 + (size % 2)]);
	avl_rec_create(root, array, size);
	return (root);
}
