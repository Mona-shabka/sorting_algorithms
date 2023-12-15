#include "sort.h"

/**
 * swap_nodes - A function that used to swap two nodes
 *		in a listint_t doubly-linked list.
 * @h: A head pointer of the doubly-linked list.
 * @n1: A pointer to 1st node to swap.
 * @n2: 2nd node to swap.
 */

void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - A function that used to sorts
 *			a doubly linked list of integers
 *			using the insertion sort algorithm.
 * @list: A head pointer of doubly-linked list of integers.
 *
 * Description: Prints list after swap.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *n_iter, *n_insert, *n_tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (n_iter = (*list)->next; n_iter != NULL; n_iter = n_tmp)
	{
		n_tmp = n_iter->next;
		n_insert = n_iter->prev;
		while (n_insert != NULL && n_iter->n < n_insert->n)
		{
			swap_nodes(list, &n_insert, n_iter);
			print_list((const listint_t *)*list);
		}
	}
}
