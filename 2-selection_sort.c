#include "sort.h"
/**
 * selection_sort - sorts an array of integers in\
 * ascending order using the Selection sort algorithm
 * @array: array to be sorted.
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, min = 0, holder = 0;

	if (size < (size_t)2)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (array[min] < array[i])
		{
			holder = array[i];
			array[i] = array[min];
			array[min] = holder;
			print_array(array, size);
		}
	}
}
