#include "sort.h"

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
 * selection_sort - A function that used to
 *		sort an array of integers in ascending order
 *		using the selection sort algorithm.
 * @array: An integers array.
 * @size: The array size.
 *
 * Description: Prints the array after each swap.
 */

void selection_sort(int *array, size_t size)
{
	int *m_min;
	size_t m, n;

	if (array == NULL || size < 2)
		return;

	for (m = 0; m < size - 1; m++)
	{
		m_min = array + m;
		for (n = m + 1; n < size; n++)
			m_min = (array[n] < *m_min) ? (array + n) : m_min;
		if ((array + m) != m_min)
		{
			swap_ints(array + m, m_min);
			print_array(array, size);
		}
	}
}
