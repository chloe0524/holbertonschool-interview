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
 * is_palindrome - checks if a linked list is a palindrome
 * @head: pointer to head of list
 * Return: 1 if palindrome, 0 if not, -1 if allocation fails
 */
int is_palindrome(listint_t **head)
{
    listint_t *tail = NULL;  // Initialize tail to NULL
    listint_t *current_head, *current_tail, *node_to_free;
    int ret_code = 1;

    // Empty list or only one value: is a palindrome
    if (*head == NULL || (*head)->next == NULL)
        return (1);

    // Create list with new nodes pointing to previous ones
    current_head = *head;
    while (current_head != NULL)
    {
        if (!add_nodeint_begin(&tail, current_head->n))
        {
            // Free allocated memory on failure
            while (tail != NULL)
            {
                node_to_free = tail;
                tail = tail->next;
                free(node_to_free);
            }
            return (-1);
        }
        current_head = current_head->next;
    }

    // Compare original list and reversed list
    current_head = *head;
    current_tail = tail;
    while (current_head != NULL)
    {
        // If different: not a palindrome
        if (current_head->n != current_tail->n)
            ret_code = 0;
        current_head = current_head->next;

        node_to_free = current_tail;
        current_tail = current_tail->next;
        free(node_to_free);
    }

    return (ret_code);
}
