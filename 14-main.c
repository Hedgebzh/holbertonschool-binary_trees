#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;
	int balance;

	root = NULL;

	balance = binary_tree_balance(root);
	printf("Balance factor for tree with root node (%p): %+d\n", (void *)root, balance);

	return (0);
}
