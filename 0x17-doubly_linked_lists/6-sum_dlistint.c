#include "lists.h"
#include <stdio.h>
/**
 * sum_dlistint - Calculates all the data of the linked list
 * @head: Is the pointer to the first node of the linked list
 * Return: The sum of all the data (n) of a dlistint_t linked list.
*/
int sum_dlistint(dlistint_t *head)
{
	const dlistint_t *temp = head;
	size_t result = 0;

	while (temp != NULL)
	{
		result += temp->n;
		temp = temp->next;
	}
	return (result);
}
