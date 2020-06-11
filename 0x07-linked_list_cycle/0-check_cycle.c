#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: pointer to the list to be checked
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *fast, *slow;

	if (!list)
		return (0);
	slow = list;
	fast = list->next;

	while (slow && fast && fast->next)
	{
		if (fast->n == slow->n)
			return (1);
		fast = fast->next->next;
		slow = slow->next;
	}
	return (0);
}
