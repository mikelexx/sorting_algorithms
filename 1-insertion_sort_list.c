#include "sort.h"
#include "stdio.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers\
 * in ascending order using the Insertion sort algorithm.
 * @list: doubly linked list pointer.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *tail = NULL, *left = NULL, *right = NULL, *right_prev = NULL,*left_prev = NULL;
	curr = (*list)->next;
	tail = *list;
	while(curr)
	{
		if (curr->n >= tail->n)
		{
			tail->next = curr;
			curr->prev = tail;
			tail = curr;
			printf("curr%d\n", curr->n);
		}
		else
		{
			left = tail;
			right = curr;
			while (left && left->n > right->n)
			{
				if (left->next == right)
				{
					right->next->prev = left;
					left->prev->next = right;
					right->prev = left->prev;
					left->next = right->next;
					right->next = left;
					left->prev = right;
					left = right->prev;
					right = left;
					continue;
				}
				printf("%d\n", left->n);
				left_prev = left->prev;
				right_prev = right->prev;
				if (left->next)
					left->next->prev = right;
				if (left->prev)
					left->prev->next = right;
				if(right->next)
					right->next->prev = left;
				right->prev->next = left;
				right->prev = left->prev;
				right->next = left->next;
				left->prev = right_prev;
				if (right_prev)
					left->next = right_prev->next->next;
				right = left;
				left = left_prev;
			}
		}
		curr = curr->next;

	}
}

