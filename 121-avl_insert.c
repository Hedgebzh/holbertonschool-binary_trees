#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * avl_to_array - creates a sorted array frome binary tree and insert a vlaue
 *
 * @tree: template tree
 * @value: value to insert
 * @array: resulting array
 * @i: starting point in array
 */
void avl_to_array(binary_tree_t *tree, int value, int *array, int *i)
{
	if (tree)
	{
		avl_to_array(tree->left, value, array, i);
		if (value < tree->n && (*i == 0 || value > array[*i - 1]))
		{
			array[*i] = value;
			(*i)++;
		}
		array[*i] = tree->n;
		(*i) = (*i) + 1;
		avl_to_array(tree->right, value, array, i);
	}
}

void avl_rec_create(avl_t *tree, int *array, size_t size)
{
	size /= 2;

	if (size)
	{
		tree->left = binary_tree_node(tree, array[size / 2]);
		if (size > 2)
			tree->right = binary_tree_node(tree, array[size + (size / 2) + 1]);
		avl_rec_create(tree->left, array, size);
		if (size > 2)
		avl_rec_create(tree->right, array + size + 1, size - 1 + (size % 2));
	}
}



avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	root = binary_tree_node(NULL, array[size / 2]);
	avl_rec_create(root, array, size);
	return root;
}

avl_t *avl_insert(avl_t **tree, int value)
{
	int *array = malloc(10000);
	int i = 0;
	int j;

	avl_to_array(*tree, value, array, &i);
	for (j = 0; j < i; j++)
		printf("%d, ", array[j]);
	printf ("\n");
	return (NULL);
}
