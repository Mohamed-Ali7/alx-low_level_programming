#include "lists.h"
#include <stdio.h>
/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list.
 * @head: Is a pointer to the pointer to the first node of the linked list
 * @n: Is the value of the element of the new node
 * Return: The address of the new node, or NULL if it failed
*/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *temp = *head;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->prev = NULL;
		return (*head);
	}
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new_node;
	new_node->prev = temp;
	return (*head);
}
