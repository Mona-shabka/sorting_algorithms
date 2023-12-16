#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - A function that used to
 *		sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t m, n, x = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);
	printf("[right]: ");
	print_array(subarr + mid, back - mid);
	for (m = front, n = mid; m < mid && n < back; x++)
		buff[x] = (subarr[m] < subarr[n]) ? subarr[m++] : subarr[n++];
	for (; m < mid; m++)
		buff[x++] = subarr[m];
	for (; n < back; n++)
		buff[x++] = subarr[n];
	for (m = front, x = 0; m < back; m++)
		subarr[m] = buff[x++];
	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - A function that used to
 *			implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integer.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */

void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t m_mid;

	if (back - front > 1)
	{
		m_mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, m_mid);
		merge_sort_recursive(subarr, buff, m_mid, back);
		merge_subarr(subarr, buff, front, m_mid, back);
	}
}

/**
 * merge_sort - A function that used to
 *		sort an array of integers in ascending
 *		order using the merge sort algorithm.
 * @array: Anintegers array.
 * @size: The array size.
 * Description: Implements the top-down merge sort algorithm.
 */

void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;
	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;
	merge_sort_recursive(array, buffer, 0, size);
	free(buffer);
}
