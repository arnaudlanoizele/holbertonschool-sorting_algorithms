#include "sort.h"

/**
 * lomuto_partition - Partitions the array using Lomuto scheme
 * @array: The array
 * @low: Starting index
 * @high: Ending index (pivot)
 * @size: Size of the array (for printing)
 * Return: The pivot index after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;
	int temp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_helper - Recursively sorts sub-arrays
 * @array: The array
 * @low: Starting index of sub-array
 * @high: Ending index of sub-array (pivot)
 * @size: Total size of the array (for printing)
 * Return: nothing (void)
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		quick_sort_helper(array, low, pivot_index - 1, size);
		quick_sort_helper(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using Quick Sort algorithm
 * @array: The array to sort
 * @size: Size of the array
 * Return: nothing (void)
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
