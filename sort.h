#ifndef SORT_H_
#define SORT_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
 * Structs, enums and unions definitions
 * Typedefs
 * Function prototypes
 */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void simple_swap(int *first, int *second);
void bubble_sort(int *array, size_t size);

void double_swap(listint_t *A, listint_t *B);
void insertion_sort_list(listint_t **list);

void selection_sort(int *array, size_t size);

int partition(int a[], int l, int h, size_t s);
void q_sort(int a[], int l, int h, size_t s);
void quick_sort(int *array, size_t size);

void d_l_list_swap_n(listint_t *a, listint_t *b, listint_t **list);
void cocktail_sort_list(listint_t **list);

void m_sort(int *a, int l, int m, int r, int *tmp);
void m_d_g(int *a, int l, int r, int *tmp);
void r_sort(int *a, int s, int e);
int find_biggest(int *a, size_t s);

void merge_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);

#endif /*SORT_H_ */
