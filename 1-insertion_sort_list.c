#include "sort.h"

/**
 * swap_list - swaps the position of two nodes in a doubly linked list
 * @list: head of the list
 * @prev: previous node
 * @node: current node
 * @next: next node
 */
void swap_list(listint_t **list, listint_t *prev,
		listint_t *node, listint_t *next)
{
	while (prev && node->n < prev->n)
	{
		if (next)
			next->prev = prev;
		node->next = prev;
		node->prev = prev->prev;
		if (prev->prev)
			(prev->prev)->next = node;
		prev->prev = node;
		prev->next = next;
		next = prev;
		prev = node->prev;
		if ((*list)->prev)
			*list = (*list)->prev;
		print_list(*list);
	}
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order
 * @list: doubly listint_t linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *prev, *next;

	if (list && *list && (*list)->next)
	{
		node = (*list)->next;
		prev = node->prev;
		next = node->next;

		while (node)
		{
			if (node->n < prev->n)
				swap_list(list, prev, node, next);
			node = next;
			if (node)
			{
				next = node->next;
				prev = node->prev;
			}
		}
	}
}
