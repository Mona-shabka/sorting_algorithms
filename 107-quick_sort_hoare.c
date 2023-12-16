#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition - A function that used to
 *			order a subset of an array of integers
 *			according to the hoare partition scheme.
 * @array: The integers array.
 * @size: The array size.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 * Return: The final partition index.
 * Description: Uses the last element of the partition as the pivot.
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int m_pivot, above, blow;

	m_pivot = array[right];
	for (above = left - 1, blow = right + 1; above < blow;)
	{
		do {
			above++;
		} while (array[above] < m_pivot);
		do {
			blow--;
		} while (array[blow] > m_pivot);
		if (above < blow)
		{
			swap_ints(array + above, array + blow);
			print_array(array, size);
		}
	}
	return (above);
}

/**
 * hoare_sort - A function that used to
 *		implement the quicksort algorithm through recursion.
 * @array: An integers array.
 * @size: The array size.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 * Description: Uses the Hoare partition scheme.
 */

void hoare_sort(int *array, size_t size, int left, int right)
{
	int m;

	if (right - left > 0)
	{
		m = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, m - 1);
		hoare_sort(array, size, m, right);
	}
}

/**
 * quick_sort_hoare - A function that used to
 *			sort an array of integers in ascending
 *			order using the quicksort algorithm.
 * @array: An integers array.
 * @size: The array size.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_sort(array, size, 0, size - 1);
}
