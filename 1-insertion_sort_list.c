#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order
 * @list: doubly listint_t linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *k, *node, *i, *j;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	k = (*list);
	while (k)
	{
		for (i = (*list)->next; i; i = i->next)
		{
			for (j = *list; j != i && j->next; j = j->next)
			{
				if (j->n > j->next->n)
				{
					node = j->next;
					if (i == node)
						i = j;
					node->prev->next = node->next;
					if (node->next != NULL)
						node->next->prev = node->prev;
					node->next = j;
					if (j == *list)
					{
						node->prev = NULL;
						*list = node;
					}
					else
					{
						j->prev->next = node;
						node->prev = j->prev;
					}
					j->prev = node;
					j = j->prev;
					print_list(*list);
				}
			}
		}
		k = k->next->next;
	}
}
