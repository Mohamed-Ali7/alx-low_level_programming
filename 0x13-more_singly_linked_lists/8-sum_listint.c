#include "lists.h"
#include <stddef.h>

/**
 * sum_listint -  Calculates the sum of all the data (n) of a linked list.
 * @head: Is the  pointer to the first node of the linked list
 * Return: The sume of all the data (n) of the listint_t linked list
 */

int sum_listint(listint_t *head)
{
	listint_t *tmp = head;
	int sum = 0;

	if (head == NULL)
	{
		return (0);
	}

	while (tmp != NULL)
	{
		sum += tmp->n;
		tmp = tmp->next;
	}
	return (sum);
}
