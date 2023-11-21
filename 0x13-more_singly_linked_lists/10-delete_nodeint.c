#include "lists.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * delete_nodeint_at_index - Deletes a new node at a given position
 * @head: Is the pointer to the pointer of the first node of the linked list
 * @index: Is the index where the node will be deleted
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *cur = *head;
	listint_t *prev;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
	{
		return (-1);
	}

	if (index == 0)
	{
		cur = *head;
		*head = (*head)->next;
		free(cur);
		return (1);
	}
	while (cur != NULL && i < index)
	{
		prev = cur;
		cur = cur->next;
		i++;
	}

	if (i != index)
	{
		return (-1);

	}
	prev->next = cur->next;
	free(cur);
	return (1);
}
