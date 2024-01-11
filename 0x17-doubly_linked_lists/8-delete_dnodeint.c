#include "lists.h"
#include <stdio.h>
/**
 * delete_dnodeint_at_index - Deletes a node at a given position.
 * @head: Is a pointer to the pointer to the first node of the linked list
 * @index: Is the position (index) of the node to be deleted
 * Return: 1 if it succeeded, -1 if it failed
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;
	dlistint_t *del_node = NULL;
	unsigned int i = 0;

	if (!*head)
		return (-1);
	if (index == 0)
	{
		del_node = *head;
		*head = (*head)->next;
		if (*head)
			(*head)->prev = NULL;
		free(del_node);
		return (1);
	}
	while (temp != NULL && i < index)
	{
		temp = temp->next;
		i++;
	}
	if (index == i)
	{
		del_node = temp;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(del_node);
		return (1);
	}
	return (-1);
}
