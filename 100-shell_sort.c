#include "sort.h"

/**
 * shell_sort - using the Shell sort algorithm, Knuth sequence
 * @array: array
 * @size: array size
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;
	ssize_t temp;

	gap = 1;
	/* Start with the largest gap and work down to a gap of 1 */
	/* 3x+1 increment sequence:  1, 4, 13, 40, 121, 364, 1093, ... */
	while (gap < size / 3)
		gap = 3 * gap + 1;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
		gap /= 3;
	}
}
