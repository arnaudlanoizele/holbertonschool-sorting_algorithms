#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		tmp = current;
		prev = current->prev;

		while (prev && tmp->n < prev->n)
		{
			/* Swap tmp and prev */
			if (prev->prev)
				prev->prev->next = tmp;
			else
				*list = tmp;

			if (tmp->next)
				tmp->next->prev = prev;

			prev->next = tmp->next;
			tmp->prev = prev->prev;
			tmp->next = prev;
			prev->prev = tmp;

			print_list(*list);
			prev = tmp->prev;
		}

		current = current->next;
	}
}
