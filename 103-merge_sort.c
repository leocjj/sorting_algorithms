#include "sort.h"

/**
 * m_sort - merge the subgroups
 * @a: array of int
 * @l: left corner index
 * @m: middle index
 * @r: right cornrer index
 * @tmp: temporary array
 *
 * Return: void
 */
void m_sort(int *a, int l, int m, int r, int *tmp)
{
	int i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(a + l, m - l);

	printf("[right]: ");
	print_array(a + m, r - m);

	i = l;
	j = m;
	k = 0;

	while (i < m && j < r)
	{
		if (a[i] < a[j])
			tmp[k++] = a[i++];
		else
			tmp[k++] = a[j++];
	}
	while (i < m)
		tmp[k++] = a[i++];
	while (j < r)
		tmp[k++] = a[j++];
	for (i = l, k = 0; i < r;)
	{
		a[i] = tmp[k];
		i++;
		k++;
	}
	printf("[Done]: ");
	print_array(a + l, r - l);
}

/**
 * m_d_g - divide in subgroups with merge algorithm
 * @a: Array to sort
 * @l: left most index of the array
 * @r: right most index of the array
 * @tmp: temporary array
 *
 * Return: void
 */
void m_d_g(int *a, int l, int r, int *tmp)
{
	int m;

	if (r - l > 1)
	{
		m = l + (r - l) / 2;
		m_d_g(a, l, m, tmp);
		m_d_g(a, m, r, tmp);
		m_sort(a, l, m, r, tmp);
	}
}

/**
 * merge_sort - divide, sort and merge
 * @array: int array
 * @size: array size
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (array == NULL || size < 2)
		return;
	tmp = malloc(sizeof(int) * size);
	m_d_g(array, 0, size, tmp);
	free(tmp);
}
