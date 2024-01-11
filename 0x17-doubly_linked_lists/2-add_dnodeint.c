#include "lists.h"
#include <stdio.h>
/**
 * add_dnodeint - Adds a new node at the beginning of a dlistint_t list.
 * @head: Is a pointer to the pointer to the first node of the linked list
 * @n: Is the value of the element of the new node
 * Return: The address of the new node, or NULL if it failed
*/
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = NULL;
		return (*head);
	}
	new_node->next = *head;
	(*head)->prev = new_node;
	*head = new_node;
	return (*head);
}
