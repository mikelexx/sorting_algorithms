#include "sort.h"
#include <stdio.h>
/**
 * print_array_section - helps in printing a section of original array.
 * @array: array whose section is to be printed.
 * @start: start index of the subsection to be printed.
 * @end: last index of the subsection to be printed.
 */
void print_array_section(int *array, size_t start, size_t end)
{
	size_t i = 0;

	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i != end)
			printf(", ");
	}
	printf("\n");
}
/**
 * merge - merges two subarrays into parent array.
 * @array: array to contain the merged subarrays(parent array).
 * @start1: start index of first sub array.
 * @end1: last index of the first sub array.
 * @start2: start index of the second sub array.
 * @end2: last index of the second sub array.
 * @copy: array that depicts 2 sub arrays where first\
 * sub array is up to its middle part and the second subarray
 * from its middle part, instead of having to create 2 entery new\
 * sub arrays.
 */
void merge(int *array, size_t start1, size_t end1, size_t start2,
		size_t end2, int *copy)
{
	size_t k = start1, start = start1, end = end2;

	printf("Merging...\n");
		printf("[left]: ");
		print_array_section(copy, start1, end1);
		printf("[right]: ");
		print_array_section(copy, start2, end2);
		while (start1 <= end1 && start2 <= end2)
		{
			if (copy[start1] < copy[start2])
				array[k]  = copy[start1++];
			else
				array[k] = copy[start2++];
			k++;
		}
		while (start1 <= end1)
		{
			array[k] = copy[start1++];
			k++;
		}
		while (start2 <= end2)
		{
			array[k] = copy[start2++];
			k++;
		}
		printf("[Done]: ");
		print_array_section(array, start, end);
}
/**
 * divide_sort - divides and array into subarrays then calls\
 * calls merge function to merge those subarrays if they can't\
 * be divided no more.
 * @array: array to be subdivided.
 * @start: starting index of the array.
 * @end: last index of the array.
 * @copy: array that mimics subdivision of the initial array\
 * int smaller sub arrays.
 */
void divide_sort(int *array, size_t start, size_t end, int *copy)
{
	size_t middle = 0, i;
	size_t interval;

	interval  = (end - start);
	if (interval % 2 == 0)
		middle = start + (interval / 2);
	else
		middle =  start + (interval / 2) + 1;
	if (start == end)
		return;
	for (i = (size_t)start; i <= (size_t)end; i++)
		copy[i] = array[i];
	divide_sort(copy, (int)start, (int)(middle) - 1, array);
	divide_sort(copy, (int)middle, (int)end, array);
	merge(array, start, middle - 1, middle, end, copy);
}
/**
 * merge_sort - sorts an array of integers in ascending\
 * order using the Merge sort algorithm.
 * Description - You must implement the top-down merge \
 * sort algorithm When you divide an array into two sub-arrays,\
 * the size of the left array should always be <= the size of the\
 * right array. i.e. {1, 2, 3, 4, 5} -> {1, 2}, {3, 4, 5}.
 * @array: array to be sorted.
 * @size: number of elements in array.
 */
void merge_sort(int *array, size_t size)
{
	int *copy = NULL;
	size_t i;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy  == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		copy[i] = array[i];
	}
	divide_sort(array, 0, size - 1, copy);
	free(copy);
}
