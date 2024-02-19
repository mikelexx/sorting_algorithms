#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending\
 * order using the Bubble sort algorithm.
 * @array: array to sort.
 * @size: size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, tmp = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size - i; j++)
		{
			if (array[j] < array[j - 1])
			{
				tmp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
}



