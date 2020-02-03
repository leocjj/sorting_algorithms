#include "sort.h"

/**
 * double_swap - swap to nodes of a double linked list
 * @A: previous node to swap
 * @B: actual node to swap.
 *
 * Return: void
 */
void double_swap(listint_t *A, listint_t *B)
{
	/* X - A - B - Y */
	listint_t *X = NULL;
	listint_t *Y = NULL;

	X = A->prev;
	Y = B->next;

	if (Y != NULL)
		Y->prev = A;
	B->prev = X;
	A->prev = B;
	if (X != NULL)
		X->next = B;
	B->next = A;
	A->next = Y;
}

/**
 * insertion_sort_list - order a double linked list
 * @list: list to order.
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = (*list)->next;
	listint_t *temp  = head;

	if (list == NULL)
		return;
	if (*list == NULL)
		return;
	
	if (head == NULL)
		return;

	while (temp != NULL)
	{
		head = temp;
		while (head->prev != NULL && (head->prev->n > head->n))
		{
			double_swap(head->prev, head);
			if (head->prev == NULL)
				*list = head;
			print_list(*list);
		}
		temp = temp->next;
	}
}
