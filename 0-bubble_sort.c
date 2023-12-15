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
 * bubble_sort - A function that used to sort an array of
 *			integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The array size.
 *
 * Description: Prints the array after each swap.
 */

void bubble_sort(int *array, size_t size)
{
	size_t m, length = size;
	bool bubb = false;

	if (array == NULL || size < 2)
		return;
	while (bubb == false)
	{
		bubb = true;
		for (m = 0; m < length - 1; m++)
		{
			if (array[m] > array[m + 1])
			{
				swap_ints(array + m, array + m + 1);
				print_array(array, size);
				bubb = false;
			}
		}
		length--;
	}
}
