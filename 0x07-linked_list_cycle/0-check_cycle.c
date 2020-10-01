#include <stdlib.h>
#include "lists.h"

/**
 * find_listint_loop - finds a loop in a listint_t linked list.
 * @head: pointer to the list
 *
 * Return: pointer to the node where the loop starts, if no loop is found,
 * the function returns NULL.
 */
int check_cycle(listint_t *head)
{
	listint_t *slow, *fast;

	if (!head || !head->next)
		return (0);

	if (head->next == head)
		return (1);

	slow = fast = head;

	do {
		slow = slow->next;
		fast = fast->next->next;
		if (!slow || !fast)
			return (0);
	} while (slow != fast);

	return (1);
}

