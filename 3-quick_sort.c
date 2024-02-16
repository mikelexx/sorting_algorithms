#include "sort.h"
#include <stdio.h>
/**
 * partition - usess the Lomuto scheme to partition the array into two
 * sub arrays where the left elements are all less that or equal to the
 * chosen element(pivot) while all element on its right are greater than it.
 * @array: array to be partitioned.
 * @start: start index of given array.
 * @end: end index of the given array.
 * @actual_size: length of original array.
 * Return: "middle" index that partitions the array using Lomuto scheme.
 */
size_t partition(int *array, size_t start, size_t end, size_t actual_size)
{
	size_t i = 0, pivot_index = start;
	int holder = 0, pivot = array[end];

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			if (pivot_index != i)
			{
			holder = array[pivot_index];
			array[pivot_index] = array[i];
			array[i] = holder;
			print_array(array, actual_size);
			}
			pivot_index++;
		}
	}
	holder = array[pivot_index];
	if (holder != pivot)
	{
	array[pivot_index] = array[end];
	array[end] = holder;
	print_array(array, actual_size);
	}
	return (pivot_index);
}
/**
 * quick_sort_helper - helps  in sorting array using squick sort argorithm.
 * @array: array to be sorted.
 * @start: start index of the array.
 * @end: end index of the array.
 * @actual_size: actual size of the original array.
 */
void quick_sort_helper(int *array, size_t start, size_t end,
		size_t actual_size)

{
	size_t middle = 0;

	if (start == end)
		return;
	middle = partition(array, start, end, actual_size);
	if (middle > start && middle < end)
	{
		quick_sort_helper(array, start, middle - 1, actual_size);
		quick_sort_helper(array, middle + 1, end, actual_size);
	}
	else if (middle == start && middle < end)
		quick_sort_helper(array, middle + 1, end, actual_size);
	else if (middle == end && middle > start)
		quick_sort_helper(array, start, middle - 1, actual_size);
}
/**
 * quick_sort - sorts an array of integers in\
 * ascending order using the Quick sort algorithm
 * @array: array to be sorted.
 * @size: size of array.
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1, size);
}
