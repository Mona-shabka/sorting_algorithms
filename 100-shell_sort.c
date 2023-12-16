#include "sort.h"

/**
 * swap_ints - A function that used to swap
 *		two integers in an array.
 * @a: The 1st integer to swap.
 * @b: The 2nd integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int temple;

	temple = *a;
	*a = *b;
	*b = temple;
}

/**
 * shell_sort - A function that used to
 *		sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An integer array.
 * @size: The array size.
 * Description: Uses the Knuth interval sequence.
 */

void shell_sort(int *array, size_t size)
{
	size_t m_gap, m, n;

	if (array == NULL || size < 2)
		return;
	for (m_gap = 1; m_gap < (size / 3);)
		m_gap = m_gap * 3 + 1;

	for (; m_gap >= 1; m_gap /= 3)
	{
		for (m = m_gap; m < size; m++)
		{
			n = m;
			while (n >= m_gap && array[n - m_gap] > array[n])
			{
				swap_ints(array + n, array + (n - m_gap));
				n -= m_gap;
			}
		}
		print_array(array, size);
	}
}
