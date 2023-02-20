#include "sort.h"

/**
 * swap - swap the position of two elements in an array
 * @array: Array
 * @ele_one: first element to swap
 * @ele_two: second element to swap
 * @size: size of Array
 */
void swap(int *array, int ele_one, int ele_two, size_t size)
{
	int temp;

	temp = array[ele_one];
	array[ele_one] = array[ele_two];
	array[ele_two] = temp;
	print_array(array, size);
}

/**
 * bubble_sort - Implementation of the bubble sort algorithm
 * @array: Array of integers to be sorted
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int swapped = true;

	if (array && size > 0)
	{
		while (swapped)
		{
			swapped = false;
			for (i = 1; i < size; i++)
			{
				if (array[i - 1] > array[i])
				{
					swap(array, i - 1, i, size);
					swapped = true;
				}
			}
			++i;
		}
	}
}
