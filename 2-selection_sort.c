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
 * selection_sort - sort an array of integers using selection sort algorithm
 * @array: array of integers to order
 * @size: size of the arrary
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, jMin;
	/* advance the position through the entire array */
	/*   (could do i < aLength-1 because single element is also min element) */
	for (i = 0; i < size - 1; i++)
	{
		/* find the min element in the unsorted a[i .. aLength-1] */
		/* assume the min is the first element */
		jMin = i;
		/* test against elements after i to find the smallest */
		for (j = i + 1; j < size; j++)
			/* if this element is less, then it is the new minimum */
			if (array[j] < array[jMin])
				jMin = j;   /* found new minimum; remember its index */
		if (jMin != i)
		{
			simple_swap(&array[i], &array[jMin]);
			print_array(array, size);
		}
	}
}
