#include "sort.h"

/**
 * rswap - recursively swap nodes
 * @list: Doubly linked list
 * @current: Current
 * @new_node: node to be swapped
 */
void rswap(listint_t **list, listint_t *current, listint_t *new_node)
{
	listint_t *previous;

	if (current->n <= new_node->n)
		return;

	else if (current->prev == NULL)
	{
		new_node->prev = current->prev;
		if (new_node->next != NULL)
			new_node->next->prev = current;
		current->prev = new_node;
		current->next = new_node->next;
		new_node->next = current;
		*list = new_node;
		print_list(*list);
	}
	else
	{
		previous = current->prev;
		current->prev->next = new_node;
		new_node->prev = current->prev;
		if (new_node->next != NULL)
			new_node->next->prev = current;
		current->prev = new_node;
		current->next = new_node->next;
		new_node->next = current;
		print_list(*list);
		rswap(list, previous, previous->next);
	}
}

/**
 * insertion_sort_list - Implementation of the insertion sort algorithm
 * @list: pointer to doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next;

	if (list == NULL)
		return;

	current = *list;

	while (current != NULL && current->next != NULL)
	{
		next = current->next;
		if (current->n > next->n)
		{
			current->next = current->next->next;
		}
		else
			current = current->next;
		rswap(list, current, next);
	}
}
