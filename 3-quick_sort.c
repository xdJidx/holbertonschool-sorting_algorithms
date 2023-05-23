#include "sort.h"

/**
 *quick_sort - function quick sort
 *@array: table
 *@size: size random of table
 */


void quick_sort(int *array, size_t size)
	{
	quickSortRecursive(array, 0, size - 1);
	}

/**
 *partition - function partition
 *@arr: table
 *@low: value
 *@high: value
 *Return: return i 
*/
	int partition(int arr[], int low, int high)
	{
		int pivot = arr[high];
		int i = low - 1;

		for (int j = low; j <= high - 1; j++)
		{
			if (arr[j] <= pivot)
			{
				i++;
				swap(&arr[i], &arr[j]);
			}
		}
		swap(&arr[i + 1], &arr[high]);

		return (i + 1);
	}

/**
 *quickSortRecursive - function
 *@arr: table
 *@low: value low
 *@high: value hight
*/

void quickSortRecursive(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		print_array(arr, high + 1);

		quickSortRecursive(arr, low, pi - 1);
		quickSortRecursive(arr, pi + 1, high);
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
	int tmp = *b;
	*b = *a;
	*a = tmp;
	}

