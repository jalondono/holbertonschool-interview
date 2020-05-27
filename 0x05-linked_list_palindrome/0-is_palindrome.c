#include "lists.h"

/**
 * is_palindrome - check if a linked list is palindrome
 * @head: head od linked list
 * Return: 0 if is palindrome
 */

int is_palindrome(listint_t **head)
{
	int idx = 0;
	int k = 0;
	listint_t *copy_head = *head;
	int *array = NULL;

	if (*head == NULL)
		return (1);

	array = malloc(sizeof(int) * 1024);
	copy_head = *head;

	for (idx = 0; copy_head != NULL; idx++)
	{
		array[idx] = copy_head->n;
		copy_head = copy_head->next;
	}
	idx--;
	if (idx < 2)
		return (1);

	for (k = 0; k <= idx / 2; ++k)
	{
		if (array[k] != array[idx - k])
			return (0);
	}
	return (1);
}
