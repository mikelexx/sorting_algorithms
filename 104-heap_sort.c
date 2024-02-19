#include "sort.h"
/**
 * build_max_heap - rearanges a given array to form max-heap.
 * @array: array to be rearranged.
 * @idx: index of the last parent in the array represention as a binary tree.
 * @size: size of the passed array.
 * @original_size: size of the original array since this is a helper function\
 * and the size of array passed to it may vary.
 */
void build_max_heap(int *array, size_t idx, size_t size, size_t original_size)
{
	size_t parent_idx = idx;
	size_t left_child_idx, right_child_idx;
	int holder = 0;

	left_child_idx = (2 * idx) + 1;
	right_child_idx = (2 * idx) + 2;
	if (left_child_idx < size && array[left_child_idx] > array[parent_idx])
		parent_idx = left_child_idx;

	if (right_child_idx < size && array[right_child_idx] > array[parent_idx])
		parent_idx = right_child_idx;
	if (parent_idx != idx)
	{
		holder = array[idx];
		array[idx] = array[parent_idx];
		array[parent_idx] = holder;
		print_array(array, original_size);
		build_max_heap(array, parent_idx, size, original_size);
	}
}
/**
 *  heap_sort - sorts an array of integers in ascending order\
 *  using the Heap sort algorithm.
 *  @array: array to be sorted.
 *  @size: number of elements of that array.
 */
void heap_sort(int *array, size_t size)
{
	size_t last_parent_idx, i;
	int holder;

	if (size < 2)
		return;

	for (last_parent_idx = (size - 1) / 2;
			(int)last_parent_idx >= 0; last_parent_idx--)
		build_max_heap(array, last_parent_idx, size, size);
	for (i = size; i > 1; i--)
	{
		holder = array[i - 1];
		array[i - 1] = array[0];
		array[0] = holder;
		print_array(array, size);
		build_max_heap(array, 0, i - 1, size);
	}
}
