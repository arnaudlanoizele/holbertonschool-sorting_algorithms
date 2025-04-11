#include "sort.h"

/**
* insertion_sort_list - sorts a doubly linked list of integers in ascending
* order using the Insertion sort algorithm
* @list: a pointer to the head of the list
*
* Return: nothing.  The list will be printed each time
* after 2 elements have been swapped
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *before, *after;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

/*Start from the second node*/
	current = (*list)->next;

	while (current != NULL)
	{
		temp = current; /*Save current node to be inserted*/
		current = current->next;

/*Move temp back to its correct position in sorted part*/
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			before = temp->prev; /*Node before temp*/
			after = temp->next; /*Node after temp*/

/*Update previous link of before node if exists*/
			if (before->prev != NULL)
			{
				before->prev->next = temp;
			}
			temp->prev = before->prev;

			temp->next = before;
			before->prev = temp;
			before->next = after;
/*Update previous link of before node if exists*/
			if (after != NULL)
				after->prev = before;
/*If tmp is now the first node, update the head of the list*/
			if (temp->prev == NULL)
				*list = temp;

			print_list(*list);
		}
	}
}
