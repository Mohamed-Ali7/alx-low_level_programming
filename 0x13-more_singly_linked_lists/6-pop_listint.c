#include "lists.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * pop_listint - Deletes the first node of the list
 * @head: Is a pointer to the first node of the list
 * Return: The data of the deleted node
 */

int pop_listint(listint_t **head)
{
	listint_t *first_node;
	int n;

	if (head == NULL || *head == NULL)
	{
		return (0);
	}
	first_node = *head;
	n = first_node->n;
	*head = (*head)->next;
	free(first_node);
	return (n);
}

