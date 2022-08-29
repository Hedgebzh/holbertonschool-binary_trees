#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * binary_tree_preorder - goes through a tree using preorder traversal
 *
 * @tree: pointer to the root of the tree to raverse
 * @func: fonction to use on each node
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
		if (tree)
		{
			func(tree->n);
			binary_tree_preorder(tree->left, func);
			binary_tree_preorder(tree->right, func);
		}
}
