#include "lists.h"

/**
 * is_palindrome - check if a linked list is palindrome
 * @head: head od linked list
 * Return: 0 if is palindrome
 */

int is_palindrome(listint_t **head)
{
	int idx = 0;
	int j = 0;
	int k = 0;
	listint_t *copy_head = *head;
	int *array = NULL;

	if (*head == NULL)
		return (1);

	for (idx = 0; copy_head->next != NULL; idx++)
	{
		copy_head = copy_head->next;
	}
	if (idx < 2)
		return (1);
	array = malloc(sizeof(int) * idx);
	copy_head = *head;
	for (j = 0; copy_head != NULL; j++)
	{
		array[j] = copy_head->n;
		copy_head = copy_head->next;
	}
	for (k = 0; k <= idx / 2; ++k)
	{
		if (array[k] != array[idx - k])
			return (0);
	}
	return (1);
}
