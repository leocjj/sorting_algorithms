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
 * partition - return the pivot index
 * @a: array
 * @l: low value (usually at index 0)
 * @h: high value (usally at last index)
 * @s: array size
 *
 * Return: pivot index
 */
int partition(int a[], int l, int h, size_t s)
{
	int pivot = a[h];
	int i = (l - 1);
	int j;

	for (j = l; j < h; j++)
	{
		if (a[j] <= pivot)
		{
			i++;

			if (i != j)
			{
				simple_swap(&a[i], &a[j]);
				print_array(a, s);
			}
		}
	}
	if (i + 1 != h)
	{
		simple_swap(&a[i + 1], &a[h]);
		print_array(a, s);
	}
	return (i + 1);
}

/**
 * q_sort - Sort the items separately
 * before and after the partition.
 * @a: array
 * @l: low value (usually at index 0)
 * @h: high value (usally at last index)
 * @s: array size
 *
 * Return: void
 */
void q_sort(int a[], int l, int h, size_t s)
{
	if (l < h)
	{
		int pv = partition(a, l, h, s);

		q_sort(a, l, pv - 1, s);
		q_sort(a, pv + 1, h, s);
	}
}

/**
 * quick_sort - divide and conquer algorithm
 * @array: array
 * @size: array size
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	q_sort(array, 0, size - 1, size);
}
