#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
#include "functions.c"
/**
 * bst_insert - checks if a binary tree is bts
 * @tree: pointer to the node
 * @value:number to insert
 * Return: 1 if it is bts 0 otherwise
 **/
avl_t *bst_insert(avl_t **tree, int value)
{
	binary_tree_t *root;

	if (!tree)
		return (NULL);
	root = *tree;
	if (!root)
	{
		*tree = binary_tree_node(root, value);
		return (*tree);
	}
	while (root->left || root->right)
	{
		if (root && (root->n > value))
		{
			if (root->left)
				root = root->left;
			else
				break;
		}
		else if (root && (root->n < value))
		{
			if (root->right)
				root = root->right;
			else
				break;
		}
		else if (root && (root->n == value))
			return (NULL);
	}
	if (root && (root->n == value))
		return (NULL);
	if (root && (root->n > value))
		return (insert_left(root, value));
	else if (root && (root->n < value))
		return (insert_right(root, value));
	return (NULL);
}
/**
 * array_to_avl - recursively set an AVL tree
 *
 * @array: The array info (pointer)
 * @size: Size of the array
 * @root: root tree
 * Return: root
 */
avl_t **array_to_avl(int *array, size_t size, avl_t **root)
{
	if (size < 1)
		return (NULL);
	bst_insert(root, array[(size - 1) / 2]);
	array_to_avl(array + (size + 1) / 2, size / 2, root);
	array_to_avl(array, size / 2, root);
	return (root);

}
/**
 * sorted_array_to_avl - set an AVL tree
 *
 * @array: The array info (pointer)
 * @size: Size of the array
 * Return: root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (!array)
		return (NULL);
	root = NULL;
	bst_insert(&root, array[(size - 1) / 2]);
	array_to_avl(array + (size + 1) / 2, size / 2, &root);
	array_to_avl(array, size / 2, &root);
	return (root);
}
