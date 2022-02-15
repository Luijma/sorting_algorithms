#include "sort.h"
/**
 * insertion_sort_list - performs insertion sort on linked list
 * @list - linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *result = NULL;
	listint_t *current = *list;
	listint_t *next;

	while (current)
	{
		next = current->next;
		print_list(result);
		current->prev = NULL;
		current->next = NULL;

		insert(&result, current);
		current = next;
	}

	*list = result;
}
/**
 * insert - helper function for insertion alg
 * @head: head of the sorted version of the list
 * @new: the new node that will be inserted
 */
void insert(listint_t **head, listint_t *new)
{
	listint_t *current;

	if (*head == NULL)
	{
		*head = new;
	} else if ((*head)->n >= new->n)
	{
		new->next = *head;
		new->next->prev = new;
		*head = new;
	} else
	{
		current = *head;

		while (current->next != NULL &&
			current->next->n < new->n)
		{
			current = current->next;
		}

		new->next = current->next;

		if (current->next != NULL)
		{
			new->next->prev = new;
		}

		current->next = new;
		new->prev = current;
	}
}
