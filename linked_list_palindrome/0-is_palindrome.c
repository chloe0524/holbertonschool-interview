#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * add_nodeint_begin - adds a new node pointing to previous one
 * @tail: pointer to pointer of latest node of listint_t list
 * @n: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *add_nodeint_begin(listint_t **tail, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *tail;
	*tail = new;
	return (*tail);
}

/**
 * is_palindrome - prints all elements of a listint_t list
 * @head: pointer to head of list
 * Return: 1 if palindrome, 0 if not, -1 if allocation fails
 */
int is_palindrome(listint_t **head)
{
	listint_t *tail = NULL;
	listint_t *current_head, *current_tail, *to_be_freed;
	int ret_code = 1;

	/* empty list or only one value: is a palindrome */
	if (*head == NULL || (*head)->next == NULL)
		return (1);

	tail = malloc(sizeof(listint_t));
	if (tail == NULL)
		return (-1); /* Not handled */

	/* Create list with new nodes pointing to previouses */
	current_head = *head;
	while (current_head != NULL)
	{
		add_nodeint_begin(&tail, current_head->n);
		current_head = current_head->next;
	}

	current_head = *head;
	current_tail = tail;
	while (current_head != NULL)
	{
		/*printf("Debug : head=%i  tail=%i\n", current_head->n, current_tail->n);*/
		/* if different : not a palindrome */
		if (current_head->n != current_tail->n)
			ret_code = 0;
		current_head = current_head->next;

		to_be_freed = current_tail;
		current_tail = current_tail->next;
		free(to_be_freed);
	}
	free(current_tail);
	return (ret_code);
}
