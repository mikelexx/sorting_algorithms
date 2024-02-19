#include "sort.h"
#include <stdio.h>
#include <stddef.h>

void free_bins(node **bins_table, size_t size)
{
	size_t i;
	node *curr = NULL, *tmp = NULL;
	printf("free sucker\n");
	for (i = 0; i < size; i++)
	{
		curr = bins_table[i];
		while (curr)
		{
			tmp = curr->next;
			free(curr);
			curr = tmp;
		}
	}
}
void copy_bins(node **bins_table, int *array, size_t size)
{
	size_t i = 0, j = 0;
	node *curr = NULL;
	printf("copy callled");
	for (i = 0; i < size; i++)
	{
		if(bins_table[i] != NULL)
		{
			curr = bins_table[i];
			while(curr)
			{
				array[j] = curr->n;
				j++;
				curr = curr->next;
			}
		}
	}
}

/**
 * radix_sort - sorts an array of integer using LSD radix sort algorithm.
 * @array: array to be sorted.
 * @size: number of elements in array.
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	int min = 0, count = 0, j = 1, lsb;
	node **bins_table = NULL, *tmp = NULL, *curr;
	for (i = 0; i < size; i++)
	{
		if (array[i] > min)
			min = array[i];
	}
	bins_table = malloc(sizeof(node *) * 10);
	if (bins_table == NULL)
		return;
	for (i = 0; i < 10; i++)
		bins_table[i] = NULL;
	while(min > 0)
	{
		count++;
		min = min/ 10;
	}
	while (j <= count)
	{
		for (i = 0; i < size; i++)
		{
			lsb = (array[i] / 10) % (10 * i);
			printf("sucker\n");
			tmp = malloc(sizeof(node));
			if (tmp == NULL)
			{
				free_bins(bins_table, size);
				return;
			}
			tmp->n = array[i];
			tmp->next = NULL;
			if (bins_table[lsb] == NULL)
				bins_table[lsb] = tmp;
			else
			{
				curr = bins_table[lsb];
				while (curr->next)
					curr = curr->next;
				curr->next = tmp;
			}
		}
		j++;
	}
	copy_bins(bins_table, array, size);
	free_bins(bins_table, size);
}
