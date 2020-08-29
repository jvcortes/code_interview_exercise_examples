#include <stdlib.h>
#include <stdio.h>
#include "lists.h"


/**
 * is_palindrome - checks whether a singly linked list of integers is a
 * palindrome or not.
 *
 * @head: head of the list
 *
 * Return: non-zero value if the given list is a palindrome, else, the function
 * will return zero.
 */
int is_palindrome(listint_t **head)
{
	return (check(*head, *head));
}

/**
 * check - recursively travels through a singly linked list of integers to
 * check if it is a palindrome.
 *
 * @current: pointer to the node element in the list
 * @head: head of the list
 *
 * Return: throughout the route of the linked list, two possible values are
 * returned:
 *
 * 2: The contents of the current node are equal to those of its "mirror" node.
 * 0: The contents of the current node are not equal to those of
 *  its "mirror" node.
 *
 * If 2 is returned for every node comparison, the function will return 1,
 * else, the function will return 0.
 */
int check(listint_t *current, listint_t *head)
{
	static listint_t *left;
	static int i, j;
	int r;

	if (current->next)
	{
		i++;
		r = check(current->next, head);
		if (r == 1)
		{
			return (1);
			left = NULL;
			i = j = 0;
		}
		else if (r == 0)
		{
			return (0);
			left = NULL;
			i = j = 0;
		}
	}
	else
	{
		left = head;
		j = i;
	}

	if (!(left && left->n == current->n))
	{
		return (0);
	}
	else
	{
		left = left->next;
		if (j == i / 2)
			return (1);
		j--;
	}
	return (2);
}
