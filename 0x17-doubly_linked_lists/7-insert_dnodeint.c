#include "lists.h"
#include <stdio.h>
/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: Is a pointer to the pointer to the first node of the linked list
 * @n: Is the value of the element of the new node
 * @idx: Is the position (index) to insert the new node
 * Return: The address of the new node, or NULL if it failed
*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *temp = *h;
	unsigned int index = 0;


	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	if (idx == 0)
	{
		new_node->n = n;
		new_node->next = *h;
		new_node->prev = NULL;
		if (*h)
			(*h)->prev = new_node;
		*h = new_node;
		return (new_node);
	}
	while (temp != NULL && index < idx - 1)
	{
		temp = temp->next;
		index++;
	}
	if (idx - 1 != index || temp == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->n = n;
	new_node->next = temp->next;
	new_node->prev = temp;
	if (temp->next)
		temp->next->prev = new_node;
	temp->next = new_node;
	return (new_node);
}
