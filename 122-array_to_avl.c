#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"


/**
* bubble_sort - sorts an array of integers in ascending order the Bubble sort
* @array : pointer array
* @size : size
*/
void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	int tmp = 0;

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size - 1 - a; b++)
		{
			if (array[b] > array[b + 1])
			{
				tmp = array[b + 1];
				array[b + 1] = array[b];
				array[b] = tmp;
			}
		}
	}
}


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
 * sorted_array_to_avl - creates an avl frome sorted array
 *
 * @array: template array
 * @size: size of array
 * Return: pointer to the root of the new tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (!array || !size)
		return (NULL);
	root = binary_tree_node(NULL, array[size / 2 - 1 + (size % 2)]);
	avl_rec_create(root, array, size);
	return (root);
}

/**
 * array_to_avl - creates an avl frome array
 *
 * @array: template array
 * @size: size of array
 * Return: pointer to the root of the new tree
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	int dup_array[1000];

	for (i = 0; i < size; i++)
		dup_array[i] = array[i];
	bubble_sort(dup_array, size);
	return (sorted_array_to_avl(dup_array, size));
}
