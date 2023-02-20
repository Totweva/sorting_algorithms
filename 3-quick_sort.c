#include "sort.h"

/**
 * swap - swap elements in array
 * @array: Array
 * @i: first element
 * @j: second element
 * @size: size of Array
 */
void swap(int *array, int i, int j, size_t size)
{
	int t;

	if (i != j)
	{
		t = array[i];
		array[i] = array[j];
		array[j] = t;
		print_array(array, size);
	}
}

/**
 * partition - partition array
 * @array: Array to be partitioned
 * @low: Low limit
 * @high: high limit
 * @size: size of array
 *
 * Return: position to partition array
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot;
	int i = (low - 1), j;

	pivot = array[high];

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array, i, j, size);
		}
	}
	swap(array, i + 1, high, size);
	return (i + 1);
}

/**
 * sort - Sort
 * @array: Array
 * @low: Low
 * @high: High
 * @size: array size
 */
void sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);

		sort(array, low, pivot - 1, size);
		sort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - implementation of quick sort algorithm
 * @array: Array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
		sort(array, 0, size - 1, size);
}
