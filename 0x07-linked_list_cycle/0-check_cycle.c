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

	while (slow != fast) {
		slow = slow->next;
		if (!slow)
			return (0);

		fast = fast->next;
		if (!fast)
			return (0);

		fast = fast->next;
		if (!fast)
			return (0);
	}

	return (1);
}

