#include <stddef.h>
#include "lists.h"
#include <stdio.h>
/**
 * get_nodeint_at_index - Finds a node of a listint_t linked list.
 * @head: Is the fisrt node of the linked list
 * @index: Is the index for the node to search for
 * Return: The node at the received index
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *node = head;
	unsigned int i = 0;

	if (head == NULL)
	{
		return (NULL);
	}

	while (node != NULL && i != index)
	{
		node = node->next;
		i++;
	}
	if (node == NULL)
	{
		return (NULL);
	}

	return (node);
}
