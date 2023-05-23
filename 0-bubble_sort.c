#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using the Bubble sort algorithm
 *
 * @array: tableau random
 * @size: size of array
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	
	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}


/**
 * swap - swap j and j + 1 value in array
 *
 * @a: value interger j
 * @b: value interger j + 1
 *
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}
