#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * max_heapify - A function that used to
 *		turn a binary tree into a complete binary heap.
 * @array: An integers array.
 * @size: The array size.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */

void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, m_large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	m_large = root;
	if (left < base && array[left] > array[m_large])
		m_large = left;
	if (right < base && array[right] > array[m_large])
		m_large = right;
	if (m_large != root)
	{
		swap_ints(array + root, array + m_large);
		print_array(array, size);
		max_heapify(array, size, base, m_large);
	}
}

/**
 * heap_sort - A function that used to
 *		sort an array of integers in ascending
 *		order using the heap sort algorithm.
 * @array: An integer array.
 * @size: The array size.
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */

void heap_sort(int *array, size_t size)
{
	int m;

	if (array == NULL || size < 2)
		return;
	for (m = (size / 2) - 1; m >= 0; m--)
		max_heapify(array, size, size, m);
	for (m = size - 1; m > 0; m--)
	{
		swap_ints(array, array + m);
		print_array(array, size);
		max_heapify(array, size, m, 0);
	}
}
