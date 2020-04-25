#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list listint
 * @head: pointer to head of list
 * @number: number to be inserted
 * Return: number of nodes
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	current = *head;

/* 0. create new node */
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;

/* 1a. *head == NULL*/
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}


/* 1a.node at the beginning */
	if (number < current->n)
	{
		new->next = (*head);
		*head = new;
		return (new);
	}

/* 2. node at the middle or end*/
	while ((current->next != NULL) && (current->next->n < number))
		current = current->next;

	new->next = current->next;
	current->next = new;

	return (new);
}
