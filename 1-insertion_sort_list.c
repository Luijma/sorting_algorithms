#include "sort.h"
/**
 * insertion_sort_list - performs insertion sort on linked list
 * @list - linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *next, *left, *right;

	if (list == NULL || *list == NULL)
		return;

	next = (*list)->next;
	while (next)
	{
		left = next->prev;
		right = next;
		next = right->next;
		while (left != NULL && left->n > right->n)
		{
			if (left->prev == NULL)
				*list = right;
			else
				left->prev->next = right;
			if (right->next)
				right->next->prev = left;

			right->prev = left->prev;
			left->next = right->next;
			left->prev = right;
			right->next = left;
			print_list(*list);
			left = right->prev;
		}
	}
}
/**
 * insert - helper function for insertion alg
 * @head: head of the sorted version of the list
 * @new: the new node that will be inserted
 */
void insert(listint_t **list, listint_t **left, listint_t **right)
{
	(*right)->prev = (*left)->prev;
	(*left)->next = (*right)->next;
	(*left)->prev = (*right);
	(*right)->next = (*left);
	print_list(*list);
	(*left) = (*right)->prev;

}
