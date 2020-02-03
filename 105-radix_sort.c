#include "sort.h"

/**
 * find_biggest - finds the maximum number
 * to know number of digits
 * @a: array
 * @s: array size
 *
 * Return: int
 */
int find_biggest(int *a, size_t s)
{
	size_t k;
	int l = 0;

	for (k = 0; k < s; k++)
	{
		if (a[k] > l)
			l = a[k];
	}
	return (l);
}

/**
 * r_sort - logic of radix_sort
 * @a: array
 * @s: array size
 * @e: exp
 *
 * Return: void
 */
void r_sort(int *a, int s, int e)
{
	int *o;
	int k;
	int c[10] = {0};

	o = malloc(sizeof(int) * s);
	for (k = 0; k < s; k++)
		c[(a[k] / e) % 10]++;
	for (k = 1; k < 10; k++)
		c[k] += c[k - 1];
	for (k = s - 1; k >= 0; k--)
	{
		o[c[(a[k] / e) % 10] - 1] = a[k];
		c[(a[k] / e) % 10]--;
	}
	for (k = 0; k < s; k++)
		a[k] = o[k];
	print_array(a, s);
	free(o);
}

/**
 * radix_sort - we sort the numbers from least significant
 * digit to most significant digit
 * @array: array
 * @size: array size
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int exp, l = find_biggest(array, size);

	if (array == NULL || size < 2)
		return;
	for (exp = 1; l / exp > 0; exp *= 10)
		r_sort(array, size, exp);
}
