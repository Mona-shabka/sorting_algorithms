#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

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
 * bitonic_merge - A function that used to
 *			sort a bitonic sequence inside an array of integers.
 * @array: An integers array.
 * @size: The array size.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The sequence size to sort.
 * @flow: The direction to sort in.
 */

void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t m, jump = seq / 2;

	if (seq > 1)
	{
		for (m = start; m < start + jump; m++)
		{
			if ((flow == UP && array[m] > array[m + jump]) ||
			    (flow == DOWN && array[m] < array[m + jump]))
				swap_ints(array + m, array + m + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - A function that used to
 *			convert an array of integers into a bitonic sequence.
 * @array: An integers array.
 * @size: The array size.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The block size of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */

void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cutt = seq / 2;
	char *string = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, string);
		print_array(array + start, seq);
		bitonic_seq(array, size, start, cutt, UP);
		bitonic_seq(array, size, start + cutt, cutt, DOWN);
		bitonic_merge(array, size, start, seq, flow);
		printf("Result [%lu/%lu] (%s):\n", seq, size, string);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - A function that used to
 *			sort an array of integers in ascending
 *			order using the bitonic sort algorithm.
 * @array: An integers array.
 * @size: The array size.
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonic_seq(array, size, 0, size, UP);
}
