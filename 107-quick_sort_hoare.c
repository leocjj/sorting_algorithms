#include "sort.h"

/**
 * simple_swap- swap to integers in an array
 * @first: first position of the array to swap
 * @second: second position of the array to swap
 *
 * Return: void
 */
void simple_swap(int *first, int *second)
{
	int copy_value = *first;
	*first = *second;
	*second = copy_value;
}

/**
 * partition_h - return the pivot index
 * @a: array
 * @l: low value (usually at index 0)
 * @h: high value (usually at last index)
 * @s: array size
 *
 * Return: pivot index
 */
int partition_h(int *a, int l, int h, size_t s)
{
	int pv = a[l];
	int k = l - 1;
	int j = h + 1;

	while (1)
	{
		do {
			k++;
		} while (a[k] < pv);
		do {
			j--;
		} while (a[j] > pv);
		if (k >= j)
			return (j);
		simple_swap(&a[k], &a[j]);
		print_array(a, s);

	}
}

/**
 * q_sort_h - Sort the item separately
 * before and after the partition
 * @a: array
 * @l: low value (usually at index 0)
 * @h: high value (usually at last index)
 * @s: array size
 *
 * Return: void
 */
void q_sort_h(int *a, int l, int h, size_t s)
{

	if (l < h)
	{
		int pv = partition_h(a, l, h, s);

		q_sort_h(a, l, pv, s);
		q_sort_h(a, pv + 1, h, s);
	}
}

/**
 * quick_sort_hoare - divide and conquer algorthm
 * with Hoare partition
 * @array: array
 * @size: array size
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	q_sort_h(array, 0, size - 1, size);
}
