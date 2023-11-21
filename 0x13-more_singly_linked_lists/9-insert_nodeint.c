#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * insert_nodeint_at_index - Inserts a new node at a given position
 * @head: Is the pointer to the pointer of the first node of the linked list
 * @idx: Is the index where the new node will be inserted
 * @n: Is the data value of the new node
 * Return: The address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node;
	listint_t *tmp = *head;
	unsigned int i = 0;

	if (head == NULL)
	{
		return (NULL);
	}
	new_node = malloc(sizeof(listint_t));
	new_node->n = n;

	while (tmp->next != NULL && i < idx - 1)
	{
		tmp = tmp->next;
		i++;
	}

	new_node->next = tmp->next;
	tmp->next = new_node;

	if (i < idx - 1 && (tmp->next == NULL || i > idx - 1))
	{
		return (NULL);

	}

	return (*head);
}
