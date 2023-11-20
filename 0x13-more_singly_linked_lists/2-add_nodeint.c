#include <stdio.h>
#include "lists.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * add_nodeint - Adds a new node at the beginning of a list_t list.
 * @head: Is the current first node of the list
 * @n: Is the integer that will be added to the list
 * Return: The address of the new node
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = (n);
	new_node->next = *head;
	*head = new_node;

	return (*head);
}
