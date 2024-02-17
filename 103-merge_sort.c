#include "sort.h"
#include <stdio.h>
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
void merge(int * array, int * array_copy, size_t start1, size_t end1, size_t start2, size_t end2)
{
	size_t k = 0, o_s = start1, o_e = end2;
	printf("merging...\n");
	while (start1 <= end1 && start2 <= end2)
	{
		if (array_copy[start1] < array_copy[start2])
		{
			array[k] = array_copy[start1];
			start1++;
		}
		else
		{
			array[k] = array_copy[start2];
			start2++;
		}
		k++;
	}
	while(start1 <= end1)
	{
		array[k] = array_copy[start1];
		start1++;
		k++;
	}
	while (start2 <= end2)
	{
		array[k] = array_copy[start2];
		start2++;
		k++;
	}
	printf("[left]: %d [right]: %d\n", array[o_s], array[o_e]);
}



	
void divide_sort(int *array, int *array_copy, size_t start, size_t end)
{
	size_t middle = 0, interval;
	int holder;

	interval  = (end - start);
	if (interval % 2 == 0)
		middle = start + (interval / 2);
	else 
		middle =  start +(interval / 2) + 1;
	printf("START: %lu END : %lu\n", start, end);
	if (start >= end)
	{
		return;
	}
	if (start + 1 >= end)
	{
		if (array_copy[start] > array_copy[end])
		{
			holder = array_copy[start];
			array_copy[start] = array_copy[end];
			array_copy[end] = holder;
			printf("after swap: %d, %d\n", array_copy[start], array_copy[end]);
		}
		else
			printf("so swap\n");
		return;
	}
	divide_sort(array, array_copy, start, middle - 1);
	divide_sort(array, array_copy, middle, end);
	merge(array, array_copy, start, middle -1, middle, end);
}

void merge_sort(int *array, size_t size)
{
	int *array_copy  = NULL;
	size_t i;
	
	array_copy = malloc(sizeof(int) * size);
	if (array_copy == NULL)
		return;
	for (i = 0; i < size; i++)
		array_copy[i] = array[i];
	divide_sort(array, array_copy, 0, size - 1);
}
