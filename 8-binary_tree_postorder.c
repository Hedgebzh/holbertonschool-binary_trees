#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * binary_tree_postorder - goes through a tree using postorder traversal
 *
 * @tree: pointer to the root of the tree to raverse
 * @func: fonction to use on each node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
		if (tree && func)
		{
			binary_tree_postorder(tree->left, func);
			binary_tree_postorder(tree->right, func);
			func(tree->n);
		}
}
