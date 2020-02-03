#include "sort.h"

/**
 * d_l_list_swap_n - swap to nodes of a double linked list
 * @a: previous node to swap
 * @b: actual node to swap.
 * @list: double linked list
 *
 * Return: void
 */
void d_l_list_swap_n(listint_t *a, listint_t *b, listint_t **list)
{
	/*x - a - b - y*/
	listint_t *x, *y;

	x = a->prev;
	y = b->next;
	if (x !=  NULL)
		x->next = b;
	else
		*list = b;
	if (y != NULL)
		y->prev = a;
	b->prev = x;
	a->next = y;
	b->next = a;
	a->prev = b;
	print_list(*list);
}

/**
 * cocktail_sort_list - Sort the elements with the movement of a windshield
 * @list: double linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *p = NULL;
	int sort_status = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	p = *list;

	while (sort_status)
	{
		sort_status = 0;
		while (p && p->next)
		{
			if (p->n > p->next->n)
			{
				d_l_list_swap_n(p, p->next, list);
				sort_status = 1;
				if (p->next)
					continue;
			}
			if (p->next == NULL)
				break;
			p = p->next;
		}
		if (!sort_status)
			break;
		while (p && p->prev)
		{
			if (p->n < p->prev->n)
			{
				d_l_list_swap_n(p->prev, p, list);
				sort_status = 1;
				if (p->prev)
					continue;
			}
			if (p->prev == NULL)
				break;
			p = p->prev;
		}
	}
}
