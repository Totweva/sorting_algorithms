#include "sort.h"

/**
 * bubble_sort - Sort an array of integers in ascending order
 * @array: An array of integers to sort
 * @size: The size of the array
 *
 * Description: Prints the array after each swap
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, n = size;
	bool bubbly = false;
	int swap;

	if(array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for(i = 0; i < n - 1; i++)
		{
			if(array[i] > array[i + 1])
			{
				swap = array[i];
				array[i] = array[i + 1];
				array[i + 1] = swap;
				print_array(array, size);
				bubbly = false;
			}
		}
		n--;
	}
}
