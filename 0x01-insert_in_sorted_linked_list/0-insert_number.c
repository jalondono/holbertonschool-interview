#include "lists.h"

/**
 * insert_node - inser a new node ina sorted list
 * @head: head of the list
 * @number: number to the new node
 * Return: pointer to the new node
 */

listint_t *insert_node(listint_t **head, int number)
	{
	listint_t *copy_head = *head;
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = number;
	new_node->next = NULL;


	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	if (number < copy_head->n)
	{
		new_node->next = (*head);
		*head = new_node;
		return (new_node);
	}

	while ((copy_head->next->n < number) && (copy_head->next != NULL))
	{
		copy_head = copy_head->next;
	}
	new_node->next = copy_head->next;
	copy_head->next = new_node;
	return (new_node);
	}
