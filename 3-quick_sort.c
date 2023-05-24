#include <stdio.h>
#include "sort.h"
/**
 * quick_sort - sorts an array of integers using the Quick sort algorithm
 * @array: tableau de integers
 * @size: taille du tableau
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
	return;
	quickSortRecursive(array, 0, size - 1, size);
}
/**
 * swap - swap two numbers
 *
 * @a: interger to swap
 * @b: interger to swap
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partition - do partition
 *
 * @array: array to sort
 * @low: start index
 * @high: end index
 * @size: size of array
 * Return: index of partition
 */
int partition(int *array, int low, int high, int size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (array[i] != array[j])
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	if (array[i + 1] != array[j])
	print_array(array, size);
	return (i + 1);
	}
/**
 * quickSortRecursive - sorts an array in ascending order
 *
 * @array: array to sort
 * @low: start index
 * @high: end index
 * @size: size of array
 *
 */
void quickSortRecursive(int *array, int low, int high, int size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);

		quickSortRecursive(array, low, pivot_index - 1, size);
		quickSortRecursive(array, pivot_index + 1, high, size);
		}
}
