#include "sort.h"

/**
 * counting_sort - sort an integer array using the Counting sort algorithm
 * @array: int array
 * @size: array size
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	size_t j = 0;
	int i = 0, max = 0, *counter = NULL, *output = NULL;

	if (array == NULL || size < 2)
		return;
	output =  calloc(size, sizeof(int));
	if (output == NULL)
		return;
	max = array[0];
	for (j = 0; j < size; j++)
		if (array[j] > max)
			max = array[j];
	counter =  calloc((max + 1), sizeof(int));
	if (counter == NULL)
		return;
	for (i = 0; i < max + 1; ++i)
		counter[i] = 0;

	/* Store count of each character */
	for (i = 0; array[i]; ++i)
		++counter[array[i]];

	/* Change count[i] so that count[i] now contains actual*/
	/*position of this character in output array*/
	for (i = 1; i <= max; ++i)
		counter[i] += counter[i - 1];
	print_array(counter, max + 1);

	/* Build the output character array*/
	for (i = size - 1; i >= 0; i--)
	{
		output[counter[array[i]] - 1] = array[i];
		--counter[array[i]];
	}

	for (j = 0; j < size; ++j)
		array[j] = output[j];

	free(counter);
	free(output);
}
