#include "lists.h"
#include <stdio.h>
/**
 * get_dnodeint_at_index - Gets a node of a dlistint_t linked list
 * in a specific index.
 *
 * @head: Is the pointer to the first node of the linked list
 * @index: Is the index of the node to return
 * Return: The node at the position of the index
*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *temp = head;
	unsigned int i = 0;

	while (temp != NULL && i <= index)
	{
		if (i == index)
			return (temp);
		temp = temp->next;
		i++;
	}
	return (NULL);
}
