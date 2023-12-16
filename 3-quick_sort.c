#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - A function that used to swap two integers in an array.
 * @a: 1st integer to swap.
 * @b: 2nd integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int temple;

	temple = *a;
	*a = *b;
	*b = temple;
}

/**
 * lomuto_partition - A function that used to
 *			order a subset of an array of integers according to
 *			the lomuto partition scheme (last element as pivot).
 * @array: The integers array.
 * @size: The array size.
 * @left: The starting index of the subset.
 * @right: The ending index of the subset.
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *m_pivot, above, below;

	m_pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *m_pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *m_pivot)
	{
		swap_ints(array + above, m_pivot);
		print_array(array, size);
	}
	return (above);
}

/**
 * lomuto_sort - A function that used to implement
 *		the quicksort algorithm through recursion.
 * @array: An integers array.
 * @size: The array size.
 * @left: The starting index of the array.
 * @right: The ending index of the array.
 * Description: Uses the Lomuto partition scheme.
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int m_part;

	if (right - left > 0)
	{
		m_part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, m_part - 1);
		lomuto_sort(array, size, m_part + 1, right);
	}
}

/**
 * quick_sort - A function that used to sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An intergers array.
 * @size: The array size.
 * Description: Uses the Lomuto partition scheme.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
