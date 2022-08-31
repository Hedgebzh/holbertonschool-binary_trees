#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"
/**
 * binary_tree_insert_left - créates a new node in left branch of binary tree
 *
 * @parent: parent of the new node
 * @value: value in new node
 * Return: the node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);
	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);
	new_node->left = parent->left;
	new_node->right = NULL;
	new_node->parent = parent;
	new_node->n = value;
	parent->left = new_node;
	if (new_node->left)
		new_node->left->parent = new_node;
	return (new_node);
}
/**
 * binary_tree_insert_right - créates new node in right branch of binary tree
 *
 * @parent: parent of the new node
 * @value: value in new node
 * Return: the node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);
	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);
	new_node->right = parent->right;
	new_node->left = NULL;
	new_node->parent = parent;
	new_node->n = value;
	parent->right = new_node;
	if (new_node->right)
		new_node->right->parent = new_node;
	return (new_node);
}
/**
 * bst_insert - créates a new node in binary search tree
 *
 * @tree: tree to insert in
 * @value: value in new node
 * Return: the node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	if ((*tree)->n < value)
	{
		if (!(*tree)->right)
			return (binary_tree_insert_right(*tree, value));
		return (bst_insert(&((*tree)->right), value));
	}
	else if ((*tree)->n > value)
	{
		if (!(*tree)->left)
			return (binary_tree_insert_left(*tree, value));
		return (bst_insert(&((*tree)->left), value));
	}
	return (NULL);
}
