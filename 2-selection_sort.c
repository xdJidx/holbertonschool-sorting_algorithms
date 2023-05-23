#include "sort.h"

/**
 *selection_sort - sorts an array of integers using the select sort algorithm
 *@array: random table
 *@size: size of array
*/


void selection_sort(int *array, size_t size)
{
	size_t i, j, small_i;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		small_i = i;
		for (j = i + 1; j < size; j++)
		if (array[j] < array[small_i])
		small_i = j;

		swap(&array[small_i], &array[i]);
		print_array(array, size);
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
