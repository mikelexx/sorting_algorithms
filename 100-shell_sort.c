#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order\
 * in ascending order using Shell sort argorithm, using the Knuth\
 * sequence.
 * @array: array to be sorted.
 * @size: size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, j, i;
	int tmp = 0;

	if (size < 2)
		return;

	while (gap < size)
		gap = gap * 3 + 1;
	if (gap > size)
		gap = (gap - 1) / 3;
	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; (int)i >= 0; i -= gap)
			{
				if (array[i] < array[i + gap])
					break;
				tmp = array[i];
				array[i] = array[i + gap];
				array[i + gap] = tmp;
			}
		}
		print_array(array, size);
	}
}
