#include "sort.h"
/**
 * quick_sort - performs quick sort on array
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recursive_sort(array, 0, ((int)size) - 1, size);
}
/**
 * swap_elements - swaps two adjacent elements
 * @a: smaller element
 * @b: bigger element
 */
void swap_elements(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * recursive_sort - performs recursion to do quick sort
 * @array: array to be sorted
 * @low: low number
 * @high: higher number
 * @size: untouched size for printing
 */
void recursive_sort(int *array, int low, int high, size_t size)
{
	int prt;

	if (low < high)
	{
		prt = partition(array, low, high, size);

		recursive_sort(array, low, prt - 1, size);

		recursive_sort(array, prt + 1, high, size);
	}
}
/**
 * partition - finds position of partition
 * @array: array to look through
 * @low: used for pointer for greater element
 * @high: used to find end
 * @size: untouched size for printing
 * Return: index of partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_elements(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	return (i);
}
