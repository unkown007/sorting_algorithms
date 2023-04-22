#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order
 * @list: doubly listint_t linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *node, *p, *head;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	head = *list;
	node = (*list)->next;
	while (node != NULL)
	{
		current = node;
		node = node->next;
		p = head;
		while (current != p && current->n > p->n)
			p = p->next;
		if (current != p)
		{
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->next = p;
			if (p == head)
			{
				current->prev = NULL;
				head = current;
			}
			else
			{
				p->prev->next = current;
				current->prev = p->prev;
			}
			p->prev = current;
			print_list(head);
		}
	}
	*list = head;
}
