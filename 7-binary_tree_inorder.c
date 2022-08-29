#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * binary_tree_inorder - goes through a tree using inorder traversal
 *
 * @tree: pointer to the root of the tree to raverse
 * @func: fonction to use on each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
		if (tree)
		{
			binary_tree_inorder(tree->left, func);
			func(tree->n);
			binary_tree_inorder(tree->right, func);
		}
}
