#include "sort.h"

void simple_swap(int *first, int *second)
{
	int copy_value = *first;
	*first = *second;
	*second = copy_value;
}

void bubble_sort_back(int *array, size_t size)
{
	size_t k, newn = 0, n = size;

	if (array == NULL || n < 2)
		return;

	do{
        newn = 0;
		for (k = 1; k <= n - 1; k++)
		{
			if (array[k - 1] > array[k])
			{
				simple_swap(&array[k - 1], &array[k]);
				/*print_array(array, size);*/
				newn = k;
			}
		}
        n = newn;
	}while(n > 1);
}
