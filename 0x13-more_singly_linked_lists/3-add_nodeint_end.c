#include <stdio.h>
#include "lists.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * add_nodeint_end - Adds a new node at the end of a list_t list.
 * @head: Is the current first node of the list
 * @n: Is the integer that will be added to the list
 * Return: The address of the new node
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *tmp = *head;

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = new_node;

	return (*head);
}
