#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - A function that used to
 *		get the maximum value in an array of integers.
 * @array: An integer array.
 * @size: The array size.
 * Return: The maximum integer in the array.
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
 * radix_counting_sort - A function that used to
 *			sort the significant digits of an array of integers
 *			in ascending order using the counting sort algorithm.
 * @array: An integer array.
 * @size: The array size.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */

void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int counter[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t m;

	for (m = 0; m < size; m++)
		counter[(array[m] / sig) % 10] += 1;
	for (m = 0; m < 10; m++)
		counter[m] += counter[m - 1];
	for (m = size - 1; (int)m >= 0; m--)
	{
		buff[counter[(array[m] / sig) % 10] - 1] = array[m];
		counter[(array[m] / sig) % 10] -= 1;
	}
	for (m = 0; m < size; m++)
		array[m] = buff[m];
}

/**
 * radix_sort - A function that used to
 *		sort an array of integers in ascending
 *		order using the radix sort algorithm.
 * @array: An integer array.
 * @size: The array size.
 * Description: Implements the LSD radix sort algorithm.
 */

void radix_sort(int *array, size_t size)
{
	int m_max, m_sig, *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	m_max = get_max(array, size);
	for (m_sig = 1; m_max / m_sig > 0; m_sig *= 10)
	{
		radix_counting_sort(array, size, m_sig, buffer);
		print_array(array, size);
	}
	free(buffer);
}
