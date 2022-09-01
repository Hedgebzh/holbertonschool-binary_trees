#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"


/**
 * quick_sort - recursif sorting algorithim based on a pivot
 *
 * @array: array to sort
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	int pivot;
	unsigned int Pos = 0;
	unsigned int TmpP = 0;
	int tmp;

	if (!array || size <= 1)
		return;
	pivot  = array[size - 1];
	while (TmpP < size - 1)
	{
		TmpP = Pos;
		while (array[TmpP] < pivot)
			TmpP++;
		if (TmpP == size - 1)
		{
			quick_sort(array, size - 1);
			break;
		}
		Pos = TmpP;
		while (array[TmpP] >= pivot && TmpP < size - 1)
			TmpP++;
		if (array[Pos] != array[TmpP])
		{
			tmp = array[Pos];
			array[Pos] = array[TmpP];
			array[TmpP] = tmp;
		}
	}
	if (Pos > 1)
		quick_sort(array, Pos);
	while (array[Pos + 1] == pivot)
		Pos++;
	if (Pos < size - 2)
		quick_sort(array + Pos + 1, size - Pos - 1);
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
	int i;
	int dup_array[size];

	for (i = 0; i < size; i ++)
		dup_array[i] = i;
	quick_sort(dup_array, size);
	return (sorted_array_to_avl(dup_array, size));
}
