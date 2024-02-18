#include "sort.h"
void bitonic_merge(int *array, size_t start, size_t count, int sort_direction, size_t size)
{
	size_t k, i;
	int check, holder;
	if (count > 1)
	{
		print_array(array, count);
		k = count / 2;
		for (i = start; i <(start + k); i++)
		{
			if (array[i] < array[i + k])
				check = 0;
			else
				check = 1;
			if (sort_direction == check)
			{
				holder = array[i];
				array[i] = array[i + k];
				array[i + k] = holder;

					
			}
		}
		bitonic_merge(array, start, k, sort_direction, size);
		bitonic_merge(array, start + k, k, sort_direction, size);
	
	}
}
void bitonic_sort_helper(int *array, size_t start, size_t count, int sort_direction, size_t size)
{
	size_t k;

	if(count > 1)
	{

		k  = count / 2;

		bitonic_sort_helper(array, start,k, 1, size);
		bitonic_sort_helper(array, (start + k), k, 0, size);
		bitonic_merge(array, start, count, sort_direction, size);
	}
}
/**
 * bitonic_sort - sorts an array of integers in\
 * ascending order using the Bitonic sort algorithm.
 * @array: array to be sorted.
 * @size:number of elements.
 */
void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_helper(array, 0, size, 1, size);
}
