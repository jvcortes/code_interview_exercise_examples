#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - adds a node inside a sorted linked list
 * @head: pointer to the linked list head.
 * @number: value of the node to insert.
 *
 * Return: inserted node, if memory allocation fails, the function will
 * return a null pointer.
 */
listint_t *insert_node(listint_t **head, const int number)
{
	listint_t *node, *next = NULL, *current = *head;

	node = malloc(sizeof(listint_t));
	if (node == NULL)
	{
		free(node);
		return (NULL);
	}
	node->n = number;
	if (*head == NULL)
	{
		*head = node;
		node->next = NULL;
		return (node);
	}
	else if ((*head)->n > number)
	{
		node->next = *head;
		*head = node;
		return (node);
	}
	while (current)
	{
		if (current->next == NULL)
		{
			next = NULL;
			break;
		}
		if (current->next->n > number)
		{
			next = current->next;
			break;
		}
		else
			current = current->next;
	}
	current->next = node;
	node->next = next;

	return (node);
}
