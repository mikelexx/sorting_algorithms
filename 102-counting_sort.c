#include "sort.h"
/**
 * counting_sort - sorts an array of integers using counting sort.
 * Description: the minimum element is assumed to be >= 0.
 * @array: array to be sorted.
 * @size: number of elements in array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int max = 0, freq_size, j, *freq = NULL, *array_copy = NULL;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	freq_size = max + 1;
	freq = malloc(sizeof(int) * freq_size);
	array_copy = malloc(sizeof(int) * size);
	if (freq == NULL || array_copy == NULL)
	{
		free(array_copy);
		free(freq);
		return;
	}
	for (j = 0; j < freq_size; j++)
		freq[j] = 0;
	for (i = 0; i < size; i++)
		freq[array[i]]++;
	for (j = 1; j < freq_size; j++)
		freq[j] = freq[j - 1] + freq[j];
	print_array(freq, freq_size);
	for (i = size - 1; (int)i >= 0; i--)
		array_copy[--freq[array[i]]] = array[i];
	for (i = 0; i < size; i++)
		array[i] =  array_copy[i];
}
