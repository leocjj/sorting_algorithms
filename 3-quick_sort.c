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
 * q_sort - sort a sub-array of integers using quick sort algorithm
 * @array: array of integers to order
 * @first: first index to sort
 * @last: last index to sort
 *
 * Return: void
 */
void q_sort(int *array, int first, int last)
{
	int i, j, pivot, temp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (array[i] <= array[pivot] && i < last)
				i++;
			while (array[j] > array[pivot])
				j--;
			if (i < j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}

		temp = array[pivot];
		array[pivot] = array[j];
		array[j] = temp;
		q_sort(array, first, j - 1);
		q_sort(array, j + 1, last);
	}
}

/**
 * quick_sort - sort an array of integers using quick sort algorithm
 * @array: array of integers to order
 * @size: size of the arrary
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	q_sort(array, 0, size - 1);
}
