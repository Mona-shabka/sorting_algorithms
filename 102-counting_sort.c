#include "sort.h"

/**
 * get_max - A function that used to
 *		get the maximum value in an array of integers.
 * @array: An integer array.
 * @size: The array size.
 * Return: The maximum integer.
 */

int get_max(int *array, int size)
{
	int m, max;

	for (max = array[0], m = 1; m < size; m++)
	{
		if (array[m] > max)
			max = array[m];
	}
	return (max);
}

/**
 * counting_sort - A function that used to
 *			sort an array of integers in ascending order
 *			using the counting sort algorithm.
 * @array: An integers array.
 * @size: The array size.
 * Description: Prints the counting array after setting it up.
 */

void counting_sort(int *array, size_t size)
{
	int *counter, *sorted, max, m;

	if (array == NULL || size < 2)
		return;
	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	counter = malloc(sizeof(int) * (max + 1));
	if (counter == NULL)
	{
		free(sorted);
		return;
	}
	for (m = 0; m < (max + 1); m++)
		counter[m] = 0;
	for (m = 0; m < (int)size; m++)
		counter[array[m]] += 1;
	for (m = 0; m < (max + 1); m++)
		counter[m] += counter[m - 1];
	print_array(counter, max + 1);

	for (m = 0; m < (int)size; m++)
	{
		sorted[counter[array[m]] - 1] = array[m];
		counter[array[m]] -= 1;
	}
	for (m = 0; m < (int)size; m++)
		array[m] = sorted[m];
	free(sorted);
	free(counter);
}
